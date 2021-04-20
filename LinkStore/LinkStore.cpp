#include <algorithm>
#include <iostream>
#include "LinkStore.hpp"

// Default constructor
LinkStore::LinkStore()
{
    this->AddLink(Link("https://rau.am/", "rau.am", LinkStatus::WAITING, 0));
}

// Getter of "allLinks"
std::vector<Link> LinkStore::GetAllLinks() const
{
    return allLinks;
}

// Returns link by url
Link LinkStore::GetByUrl(const std::string& url)
{
    
    for(int i = 0; i < allLinks.size(); ++i)
    {
        if(allLinks[i].GetURL() == url)
            return allLinks[i];
    }
    
    return Link();
}

// Returns vector<Link> vec(size) by domain and status
std::vector<Link> LinkStore::GetBy(const std::string& domain, LinkStatus status, std::size_t size)
{
    std::vector<Link> links;

    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < allLinks.size(); ++i)
        {
            if(allLinks[j].GetDomain() == domain && allLinks[j].GetStatus() == status)
            {
                links.push_back(allLinks[j]);
                break;
            }
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

// Adds new link to "allLinks"
void LinkStore::AddLink(const Link& link)
{   
    if(!ContainsLink(link.GetURL()))
        allLinks.push_back(link);
}

// Updates the info of link
void LinkStore::Update(const Link& link)
{
    for(auto it = allLinks.begin(); it != allLinks.end(); ++it)
    {
        if((*it).GetURL() == link.GetURL())
            *it = link;    
    }
}

