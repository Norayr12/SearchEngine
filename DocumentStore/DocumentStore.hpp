#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../DBConnector/DBConnector.hpp"
#include "Document.hpp"


class DocumentStore
{

public:
    // Default constructor
    DocumentStore();

    // Get document by title
    Document GetByTitle(const std::string& title);

    // Add new document
    void AddNewDocument(Document document);

};