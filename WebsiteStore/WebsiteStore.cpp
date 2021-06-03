#include <iostream>
#include "WebsiteStore.hpp"

// Default constructor
WebsiteStore::WebsiteStore()
{
    sql::ResultSet* resultSet = DBConnector::ExecuteQuery("SELECT * FROM Crawler.Websites;");

    while(resultSet->next())
    {
        std::string domain = resultSet->getString("domain");
        std::string url = resultSet->getString("homepage");

        // TODO: CHANGE THIS TO SECONDS ,CAUSE NOW IT IS YEAR OF LAST UPDATE
        uint32_t lastCrawlingTime;
        lastCrawlingTime = resultSet->getUInt("lastCrawlingTime");
        std::cout << std::endl << resultSet->getInt(1) << " " << domain << " " << url << " " << lastCrawlingTime << std::endl;
        this->AddNew(Website(domain, url, lastCrawlingTime));
    }
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
    DBConnector::ExecuteQuery("UPDATE Crawler.Websites SET lastCrawlingTime = current_timestamp() WHERE domain = '" + website.GetDomain() + "'" );
}