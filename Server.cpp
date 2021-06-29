#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

//#include <nuspell/dictionary.hxx>
//#include <nuspell/finder.hxx>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/beast/core/buffers_to_string.hpp>

//#include "SpellChecker/SpellChecker.hpp"
#include "DBConnector/DBConnector.hpp"

using tcp = boost::asio::ip::tcp;


std::string ToJSON(std::string& url, std::string& title, std::string& description)
{
    boost::property_tree::ptree out;
    out.put("url", url);
    out.put("title", title);
    out.put("description", description);

    std::ostringstream oss;
    boost::property_tree::write_json(oss, out);

    return oss.str();
}


std::vector<std::string> Split (const std::string& query, char separator)
{
    std::vector<std::string> words;
    int from = 0, to = 0;
    while((to = query.find(separator, to)) != std::string::npos)
    {
        ++to;
        words.push_back(query.substr(from, to - from - 1));
        from = to;
    }
    words.push_back(query.substr(from, query.size() - from));
    return words;
}

int main()
{

    DBConnector::Init("tcp://127.0.0.1:3306", "root", "Norik262220");

    /*
    SpellChecker checker;
    checker.Init();

    std::string query;
    std::getline(std::cin, query);
    std::vector<std::string> allWords = Split(query, ' ');

    std::vector<std::vector<std::string>> suggestions (allWords.size());
    if(checker.CheckQuery(allWords, suggestions))
    {
        std::cout << "CORRECT";
    }
    else
    {
        for(int i = 0; i < allWords.size(); ++i)
        {
            std::cout << "Suggestions for \"" << allWords[i] << "\" :" << "\n";
            for(int j = 0; j < suggestions[i].size(); ++j)
                std::cout << suggestions[i][j] << "\n";

        }
    }
    */

    auto const address = boost::asio::ip::make_address("127.0.0.1");
    auto const port = static_cast<unsigned short>(std::atoi("8081"));
    boost::asio::io_context ioc{1};

    boost::asio::ip::tcp::acceptor acceptor{ioc, {address, port}};

    while(1)
    {
        tcp::socket socket{ioc};
        acceptor.accept(socket);
        std::cout << "socket accepted" << "\n";

        std::thread{[q = std::move(socket)]() mutable {

            boost::beast::websocket::stream<tcp::socket> ws {std::move(q)};
            ws.accept();
            while(1)
            {
                try
                {
                    boost::beast::flat_buffer buffer;

                    ws.read(buffer);
                    std::string out = boost::beast::buffers_to_string(buffer.data());
                    std::string result = "";
                    sql::ResultSet* resultSet = DBConnector::ExecuteQuery("SELECT * FROM Crawler.Data WHERE MATCH title AGAINST ('" + out + "' IN BOOLEAN MODE);");

                    while(resultSet->next())
                    {
                        std::string url = resultSet->getString("url");
                        std::string title = resultSet->getString("title");
                        std::string description = resultSet->getString("description");
                        result += ToJSON(url, title, description) + ",";
                    }

                    result = "{\n \"data\":[\n" + result.substr(0, result.size() - 2) + "\n]}";
                    std::cout << result << "\n";
                    ws.write(boost::asio::buffer(std::basic_string<char>(result)));
                    std::cout << out << "\n";
                }
                catch (boost::beast::system_error const& e)
                {
                    if(e.code() != boost::beast::websocket::error::closed)
                    {
                        std::cout << "Error catch: " << e.code().message() << "\n";
                        break;
                    }
                }

            }

        }}.detach();
    }

}
