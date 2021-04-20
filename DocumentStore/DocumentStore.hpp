#include <vector>
#include <unordered_map>
#include "Document.hpp"


class DocumentStore
{

private:
    // All documents
    std::unordered_map<std::string, Document> docs;

public:
    // Default constructor
    DocumentStore();
    
    // Get all documents
    std::vector<Document> GetAllDocuments();

    // Get document by title
    Document GetByTitle(const std::string& title);

    // Add new document
    void AddNewDocument(const Document& document);

};