#include "Link.hpp"

// Default constructor
Link::Link()
{
    url = "";
}

// Constructor with params
Link::Link(const std::string& url, const std::string& domain, const LinkStatus status, const time_t lastLoadTime) :
    url { url }, domain { domain }, status { status }, lastLoadTime { lastLoadTime }
{}

// Getters
const std::string& Link::GetDomain() const
{
    return this->domain;
}

const std::string& Link::GetURL() const
{
    return this->url;
}

LinkStatus Link::GetStatus() const
{
    return this->status;
}

time_t Link::GetLastLoadTime() const
{
    return this->lastLoadTime;
}
//

// "==" operator overloading
bool operator== (const Link& left, const Link& right)
{
    return left.GetURL() == right.GetURL();
}