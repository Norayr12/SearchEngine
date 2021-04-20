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
    Link GetByUrl(const std::string& url);
    std::vector<Link> GetBy(const std::string& domain, LinkStatus status, std::size_t size);

    // Add new link to 'allLinks' collection
    void AddLink(const Link& link);

    // Update the information about link in 'allLinks'
    void Update(const Link& link);

    // Delete link from 'allLinks' collection
    void DeleteLink(Link& link);

    // Check if LINK contains in all list
    bool ContainsLink(const std::string& link); 

    // All links getter
    std::vector<Link> GetAllLinks() const;
};


#endif //LinkStore_hpp