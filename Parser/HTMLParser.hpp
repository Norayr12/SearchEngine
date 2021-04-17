#ifndef PARSER
#define PARSER
#include <gumbo.h>
#include <iostream>
#include <vector>

class HTMLParser
{

public:
    // Extract all links from page
    static void SearchLinks (GumboNode* node, std::vector<std::string>& links);

    // Extract all documents from page
    static std::string SearchText (GumboNode* node);
};
#endif