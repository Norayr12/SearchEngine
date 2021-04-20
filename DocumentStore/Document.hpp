#ifndef Document_hpp
#define Document_hpp

#include <string>

class Document
{

private:

    // Document url
    std::string url;

    // Title of document from page
    std::string title;

    // All text
    std::string allText;

    // Description of page
    std::string description;

public:

    // Default constructor
    Document();

    // Constructor with params
    Document(const std::string& url, const std::string& title, const std::string& allText, const std::string& description); 

    // Getters of fields
    const std::string& GetURL() const;
    const std::string& GetTitle() const;
    const std::string& GetAllText() const;
    const std::string& GetDescription() const;
    //
};

#endif //Document_hpp