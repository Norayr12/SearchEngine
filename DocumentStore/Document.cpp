#include "Document.hpp"

Document::Document()
{
    body = nullptr;
}

Document::Document(const std::string& title, const std::string& body) :
    title { title }, body { body }
{}