#include "DocumentStore.hpp"

// Default constructor
DocumentStore::DocumentStore()
{}

// Returns DOCUMENT by title
Document DocumentStore::GetByTitle(const std::string& title)
{
    return Document();
}

// Adds new document to "docs"
void DocumentStore::AddNewDocument(Document document)
{
    std::string url = document.GetURL();
    std::string title = document.GetTitle();
    std::string data = document.GetAllText();
    std::string description = document.GetDescription();

    std::string updateQuery = "UPDATE Crawler.Data SET title = '" + title + "', data = '" + data + "', description = '" + description + "' WHERE url = '" + url + "'";
    try
    {
        DBConnector::ExecuteQuery("INSERT INTO Crawler.Data values ( '" + url + "', '" + title + "', '" + data + "', '" + description + "' )");
    }
    catch (sql::SQLException& e)
    {
        if(e.getErrorCode() == 1062 || e.getErrorCode() == 1061)
            DBConnector::ExecuteQuery(updateQuery);
        else
        {

        }
            //std::cout << e.what() << "\n";
    }
}