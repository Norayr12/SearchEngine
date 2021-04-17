#include "Website.hpp"

Website::Website()
{

}

Website::Website(const std::string& domain, const std::string& homepageUrl, const time_t lastCrawlingTime) :
  domain { domain }, homepageUrl { homepageUrl }, lastCrawlingTime { lastCrawlingTime }  
{}

std::string Website::GetDomain()
{
    return domain;
}

std::string Website::GetHomepage()
{
    return homepageUrl;
}

time_t Website::GetLastCrawlingTime()
{
    return lastCrawlingTime;
}