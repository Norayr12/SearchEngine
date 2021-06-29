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

    std::vector<std::string> insertValues = {url, title, data, description};
    std::vector<std::string> updateValues = {title, data, description, url};

    std::string updateQuery = "UPDATE Crawler.Data SET title = ?, data = ?, description = ? WHERE url = ?" ;
    try
    {
        DBConnector::ExecuteQuery("INSERT INTO Crawler.Data values (?, ?, ?, ?)", insertValues);
    }
    catch (sql::SQLException& e)
    {
        if(e.getErrorCode() == 1062 || e.getErrorCode() == 1061)
            DBConnector::ExecuteQuery(updateQuery, updateValues);
    }
}