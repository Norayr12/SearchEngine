#include "DocumentStore.hpp"

std::vector<Document> DocumentStore::GetAllDocuments()
{
    return docs;
}

void DocumentStore::AddNewDocument(const Document& document)
{
    docs.push_back(document);
}