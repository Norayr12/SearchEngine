#include "Document.hpp"

// Default constructor
Document::Document()
{
    this->allText = nullptr;
}

// Costructor with params
Document::Document(const std::string& url, const std::string& title, const std::string& allText, const std::string& description) :
    url { url }, title { title }, allText { allText }, description { description }
{}

// Getters
const std::string& Document::GetURL() const
{
    return this->url;
}

const std::string& Document::GetAllText() const 
{
    return this->allText;
}

const std::string& Document::GetTitle() const
{
    return this->title;
}

const std::string& Document::GetDescription() const
{
    return this->description;
}
//