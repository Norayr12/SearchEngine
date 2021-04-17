#include "WebsiteStore.hpp"

WebsiteStore::WebsiteStore()
{
    this->AddNew(Website("rau.am", "https://rau.am/", 0));
}

std::vector<Website> WebsiteStore::GetAll() const
{
    std::vector<Website> websites;
    for(auto it = all.begin(); it != all.end(); ++it)
    {
        websites.push_back((*it).second);
    }
}

void WebsiteStore::AddNew(const Website& website)
{
    all.insert({ (website.GetHomepage(), website) });
}

void WebsiteStore::Update(const Webstite& website)
{
    all[website.GetURL()] = website;
}