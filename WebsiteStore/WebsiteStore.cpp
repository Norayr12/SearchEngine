#include <iostream>
#include "WebsiteStore.hpp"

// Default constructor
WebsiteStore::WebsiteStore()
{
    this->AddNew(Website("rau.am", "https://rau.am/", 0));
}

// All websites getter
std::vector<Website> WebsiteStore::GetAll() const
{
    std::vector<Website> websites;
    for(auto it = all.begin(); it != all.end(); ++it)
    {
        websites.push_back((*it).second);
    }
    
    return websites;
}

// Adds new website
void WebsiteStore::AddNew(const Website& website)
{
    all.insert({ website.GetHomepage(), website });
}

// Updates the website info
void WebsiteStore::Update(const Website& website)
{
    all[website.GetHomepage()] = website;
}