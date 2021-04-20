#include <cassert>
#include "HTMLParser.hpp"

// Returns parsed DOCUMENT
Document HTMLParser::GetDocument(GumboNode* node)
{     
    return Document("url" ,SearchTitle(node), SearchText(node), "description");
}

// Recursively fills the vector
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

// Returns the title from page
std::string HTMLParser::SearchTitle(GumboNode* node)
{
    assert(node->type == GUMBO_NODE_ELEMENT);
    assert(node->v.element.children.length >= 2);

    const GumboVector* root_children = &node->v.element.children;
    GumboNode* head = NULL;
    for (int i = 0; i < root_children->length; ++i) 
    {
        GumboNode* child = (GumboNode*)root_children->data[i];
        if (child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_HEAD) 
        {
            head = child;
            break;
        }
    }

    assert(head != NULL);

    GumboVector* head_children = &head->v.element.children;

    for (int i = 0; i < head_children->length; ++i) 
    {
        GumboNode* child = (GumboNode*)head_children->data[i];

        if (child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_TITLE) 
        {
            if (child->v.element.children.length != 1) 
            {
                return "<title is empty>";
            }

            GumboNode* title_text = (GumboNode*)child->v.element.children.data[0];
            assert(title_text->type == GUMBO_NODE_TEXT || title_text->type == GUMBO_NODE_WHITESPACE);

            return title_text->v.text.text;
        }
    }

    return "<title not found>";
}

// Returns the all text from page
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