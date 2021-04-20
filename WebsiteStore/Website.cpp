#include "Website.hpp"

// Default constructor
Website::Website()
{}

// Constructor with params
Website::Website(const std::string& domain, const std::string& homepageUrl, const time_t lastCrawlingTime) :
  domain { domain }, homepageUrl { homepageUrl }, lastCrawlingTime { lastCrawlingTime }  
{}

// Getters
const std::string& Website::GetDomain() const
{
    return domain;
}

const std::string& Website::GetHomepage() const
{
    return homepageUrl;
}

const time_t& Website::GetLastCrawlingTime() const
{
    return lastCrawlingTime;
}
//