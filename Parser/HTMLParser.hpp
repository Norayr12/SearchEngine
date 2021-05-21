#ifndef PARSER
#define PARSER

#include <string>
#include <vector>
#include <optional>
#include <functional>
#include <tuple>

#include <gumbo.h>

class Parser {
    
private:
    
    /**
     * The effective url.
     */
    std::string url;
    
    /**
     * The effective url host.
     */
    std::string urlHost;
    
    /**
     * The effective url path.
     */
    std::string urlPath;
    
    /**
     * The effective url scheme.
     */
    std::string urlScheme;
    
    /**
     * The entire HTML document.
     */
    std::string html;
    
    /**
     * All urls.
     */
    std::vector<std::string> urls;
    
    /**
     * Title inside <head>.
     */
    std::string title;
    
    /**
     * Content of the content attribute of <meta name="description" content="Some content">
     */
    std::string description;
    
    /**
     * All clean text.
     */
    std::string allText;
    
private:

    // Extract all urls.
    void ExtractUrls(GumboNode* node);
    
    // Extracts clean text.
    std::string ExtractCleanText(GumboNode* node) const;
    
    // Extracts title tag content of the head tag.
    std::string ExtractTitle(const GumboNode* root) const;
    
    // Extract content of the content attribute of <meta name="description" content="Some content">
    void ExtractDescription(GumboNode* node);
    
    // Returns the scheme of url.
    static std::optional<std::string> Scheme(const std::string& url);
    
    // Returns The host of url.
    static std::optional<std::string> Host(const std::string& url);
    
    // Return The path of url.
    static std::optional<std::string> Path(const std::string& url);
    
    
    std::tuple<std::string, std::string, std::string> ParseUrl(const std::string& url) const;
    
    // Check if url is a page fragment
    bool IsPageFragment(const std::string& url) const;

public:
    
    /**
     * Parse the HTML document.
     * @param url The effective url.
     * @param html The entire HTML document.
     */
    Parser(const std::string& url, const std::string& html);
    
    /**
     * Parse the HTML document.
     */
    void Parse();
    
    /**
     * @return All urls.
     */
    const std::vector<std::string>& GetUrls() const;
    
    /**
     * @return Title tag content of the head tag.
     */
    const std::string& GetTitle() const;
    
    /**
     * @return Content of the content attribute of <meta name="description" content="Some content">
     */
    const std::string& GetDescription() const;
    
    /**
     * @return All clean text.
     */
    const std::string& GetAllText() const;
   
};
#endif //PARSER