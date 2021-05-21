#include <algorithm>
#include <iostream>
#include "LinkStore.hpp"

// Default constructor
LinkStore::LinkStore()
{

}

// Getter of "allLinks"
std::vector<Link> LinkStore::GetAllLinks() const
{
    return allLinks;
}

// Returns link by url
std::optional<Link> LinkStore::GetByUrl(const std::string& url)
{
    for (const auto& link : allLinks) {
        if (link.GetURL() == url) {
            return link;
        }
    }
    return {};
}

// Returns vector<Link> vec(size) by domain and status
std::vector<Link> LinkStore::GetBy(const std::string& domain, LinkStatus status, std::size_t size)
{
    std::vector<Link> links;

    for (int i = 0; i < allLinks.size(); ++i)
    {
        if(size == 0)
            break;
        if(allLinks[i].GetStatus() == status)
        {
            links.push_back(allLinks[i]);
            --size;
        }
    }

    return links;
}

// Returns true if link is already exist in "allLinks"
bool LinkStore::ContainsLink(const std::string& link)
{
    for(int i = 0; i < allLinks.size(); ++i)
    {
        if(allLinks[i].GetURL() == link)       
            return true;   
    }

    return false;
}

// Returns true if ALL LINKS IS LOADED
bool LinkStore::AllLoaded()
{
    for (const auto& link : allLinks)
    {
        if(link.GetStatus() == LinkStatus::WAITING)
            return false;
    }
    return true;
}


// Adds / updates new link to "allLinks"
void LinkStore::Save(const Link& link)
{
    for(int i = 0; i < allLinks.size(); ++i)
    {
        if(allLinks[i].GetURL() == link.GetURL())
        {
            allLinks[i] = link;
            return;
        }
    }

    allLinks.push_back(link);
}

