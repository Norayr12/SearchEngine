#ifndef Document_hpp
#define Document_hpp

#include <string>

class Document
{

private:

    // Title of document from page
    std::string title;

    // Body text
    std::string body;

public:

    // Default constructor
    Document();

    // Constructor with params
    Document(const std::string& title, const std::string& body); 

    // Getters of fields
    std::string GetTitle();
    std::string GetBody();
    //
};

#endif Document_hpp