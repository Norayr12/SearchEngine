#ifndef Website_hpp
#define Website_hpp

#include <string>

class Website 
{
    
private:
    // Domain of website, for example "google.com"   
    std::string domain;

    // URI of the main page, for example "https://google.com"
    std::string homepageUrl;

    // Last crawling time in miliseconds
    time_t lastCrawlingTime;
    
    
public:
    
    // Default constructor
    Website();

    // Constructor with params
    Website(const std::string& domain, const std::string& homepageUrl, const time_t lastCrawlingTime);

    // Getters of fields
    std::string GetDomain();
    std::string GetHomepage();
    time_t GetLastCrawlingTime();

};


#endif Website_hpp