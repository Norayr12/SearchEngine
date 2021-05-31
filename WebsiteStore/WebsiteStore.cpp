#include <iostream>
#include "WebsiteStore.hpp"

// Default constructor
WebsiteStore::WebsiteStore()
{

    sql::Driver* driver;
    sql::Connection* connection;
    sql::Statement* statement;
    sql::ResultSet* resultSet;

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "Norik262220";

    try
    {
        driver = get_driver_instance();
        connection = driver->connect(host, username, password);
        connection->setSchema("Crawler");
        statement = connection->createStatement();

        resultSet = statement->executeQuery("SELECT * FROM Crawler.Websites;");
        sql::ResultSetMetaData* md = resultSet->getMetaData();

        while(resultSet->next())
        {
            std::string domain, url;
            uint32_t lastCrawlingTime;
            domain = resultSet->getString("domain");
            url = resultSet->getString("homepage");

            // TODO: CHANGE THIS TO SECONDS ,CAUSE NOW IT IS YEAR OF LAST UPDATE
            lastCrawlingTime = resultSet->getUInt("lastCrawlingTime");
            std::cout << std::endl << resultSet->getInt(1) << " " << domain << " " << url << " " << lastCrawlingTime << std::endl;
            this->AddNew(Website(domain, url, lastCrawlingTime));
        }
        statement->executeQuery("UPDATE Crawler.text SET domain = 'changed' WHERE url = 'res'");
    }
    catch (sql::SQLException& e)
    {
        std::cout << e.what() << std::endl;
    }

}

// All websites getter
std::vector<Website> WebsiteStore::GetAll() const
{
    std::vector<Website> websites;
    for(auto it = all.begin(); it != all.end(); ++it)
    {
        websites.push_back((*it).second);
    }
    
    return websites;
}

// Adds new website
void WebsiteStore::AddNew(const Website& website)
{
    all.insert({ website.GetHomepage(), website });
}

// Updates the website info
void WebsiteStore::Update(const Website& website)
{
    all[website.GetHomepage()] = website;
}