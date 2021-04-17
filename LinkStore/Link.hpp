#ifndef Link_hpp
#define Link_hpp
#include <string>
#include "LinkStatus.hpp"

class Link
{
private:

    // Link URI
    std::string url;

    // Domain of current link
    std::string domain;
    
    // Status of link, for example : "WAITING" or "LOADED"
    LinkStatus status;

    // Last load time
    time_t lastLoadTime;

public:

    // Default constructor
    Link();

    // Constructor with params
    Link(const std::string& url, const std::string& domain, const LinkStatus status, const time_t lastLoadTime);
    
    // Getters of fields
    std::string GetURL() const;

    std::string GetDomain() const;

    LinkStatus GetStatus() const;

    time_t GetLastLoadTime() const;
    //

    // == operator overloading by URL
    friend bool operator==(const Link& a, const Link& b);
};

#endif Link_hpp