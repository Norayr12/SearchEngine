#include "DocumentStore.hpp"

// Default constructor
DocumentStore::DocumentStore()
{}

// Getter
std::vector<Document> DocumentStore::GetAllDocuments()
{
    std::vector<Document> documents;
    
    for(auto it = docs.begin(); it != docs.end(); ++it)
    {
        documents.push_back((*it).second);
    }

    return documents;
}

// Returns DOCUMENT by title
Document DocumentStore::GetByTitle(const std::string& title)
{
    for(int i = 0; i < docs.size(); ++i)
    {
        
    }
    return Document();
}

// Adds new document to "docs"
void DocumentStore::AddNewDocument(const Document& document)
{
    docs.insert( { document.GetURL(), document } );
}