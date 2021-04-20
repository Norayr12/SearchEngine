#ifndef PARSER
#define PARSER
#include <gumbo.h>
#include <iostream>
#include <vector>
#include "../DocumentStore/Document.hpp"

class HTMLParser
{

public:
    
    // Returns parsed DOCUMENT
    static Document GetDocument(GumboNode* node);

    // Extract all links from page
    static void SearchLinks (GumboNode* node, std::vector<std::string>& links);

    // Returns the title of page
    static std::string SearchTitle(GumboNode* node);

    // Returns the all text from page
    static std::string SearchText (GumboNode* node);
};
#endif //PARSER