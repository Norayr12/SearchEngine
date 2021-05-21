#ifndef LinkStore_hpp
#define LinkStore_hpp

#include <optional>
#include <vector>
#include "Link.hpp"

class LinkStore 
{
    
private:

    // All links collection
    std::vector<Link> allLinks;

public:

    // Default constructor
    LinkStore();

    // Get link by params
    std::optional<Link> GetByUrl(const std::string& url);
    std::vector<Link> GetBy(const std::string& domain, LinkStatus status, std::size_t size);

    // Adds / updates new link to 'allLinks' collection
    void Save (const Link& link);

    // Check if LINK contains in all list
    bool ContainsLink(const std::string& link);
    
    // Check if ALL LINKS IS LOADED
    bool AllLoaded();

    // All links getter
    std::vector<Link> GetAllLinks() const;
};
#endif