#include "HTMLParser.hpp"


void HTMLParser::SearchLinks (GumboNode* node, std::vector<std::string>& links)
{
    if(node->type != GUMBO_NODE_ELEMENT)
        return;

    GumboAttribute* href;

    if (node->v.element.tag == GUMBO_TAG_A && (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) 
        links.push_back(href->value);

    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i)
        SearchLinks((GumboNode*)children->data[i], links);
}

std::string HTMLParser::SearchText (GumboNode* node)
{
    if (node->type == GUMBO_NODE_TEXT) 
    {
        return std::string(node->v.text.text);
    } 
    else if (node->type == GUMBO_NODE_ELEMENT && node->v.element.tag != GUMBO_TAG_SCRIPT && node->v.element.tag != GUMBO_TAG_STYLE) 
    {
        std::string contents = "";
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) 
        {
            const std::string text = SearchText((GumboNode*) children->data[i]);
            if (i != 0 && !text.empty()) 
            {
                contents.append(" ");
            }
            contents.append(text);
        }

        return contents;
    } 
    else 
    {
        return "";
    }
}