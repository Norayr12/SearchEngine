#include "Link.hpp"

Link::Link()
{
    url = nullptr;
}

Link::Link(const std::string& url, const std::string& domain, const LinkStatus status, const time_t lastLoadTime) :
    url { url }, domain { domain }, status { status }, lastLoadTime { lastLoadTime }
{}

std::string Link::GetDomain() const
{
    return domain;
}

std::string Link::GetURL() const
{
    return url;
}

LinkStatus Link::GetStatus() const
{
    return status;
}

time_t Link::GetLastLoadTime() const
{
    return lastLoadTime;
}

bool operator== (const Link& left, const Link& right)
{
    return left.GetURL() == right.GetURL();
}