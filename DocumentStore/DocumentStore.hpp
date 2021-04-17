#include <vector>
#include "Document.hpp"

class DocumentStore
{

private:
    // All documents
    std::vector<Document> docs;

public:
    // Get all documents
    std::vector<Document> GetAllDocuments();

    // Get document by title
    Document GetByTitle(const std::string& title);

    // Add new document
    void AddNewDocument(const Document& document)

};