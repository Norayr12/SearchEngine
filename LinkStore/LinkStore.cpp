#include <algorithm>
#include "LinkStore.hpp"

std::vector<Link> LinkStore::GetAllLinks() const
{
    return allLinks;
}

Link LinkStore::GetByUrl(const std::string& url) const
{
    for(auto it = allLinks.begin(); it != allLinks.end(); ++it)
    {
        if((*it).GetURL() == url)
            return *it;
    }
    
    return Link();
}

std::vector<Link> LinkStore::GetBy(const std::string& domain, LinkStatus status, std::size_t size)
{
    std::vector<Link> links;


    return links;
}

void LinkStore::AddLink(Link& link)
{   
    if(std::find(allLinks.begin(), allLinks.end(), link)) != allLinks.end())
        allLinks.pushback(link);
}

void LinkStore::Update(Link& link)
{
    for(auto it = allLinks.begin(); it != allLinks.end(); ++it)
    {
        if((*it).GetURL() = link.GetURL())
            *it = link;    
    }
}

