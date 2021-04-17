#include <iostream>
#include <string>
#include <vector>
#include "WebsiteStore.hpp"
#include "LinkStore.hpp"
#include "PageLoader.hpp"
#include "HTMLParser.hpp"

int main()
{
    WebsiteStore websiteStore;
    LinkStore linkStore;
    PageLoader pageLoader;

    const auto& websites = websiteStore.GetAll();

    for(const auto& website : websites)
    {
        const auto& homepageLink = linkStore.GetByUrl(website.GetHomepage());

        if(homepageLink.GetURL() != nullptr)
        {
            linkStore.Update(Link(website.GetHomepage(), website.GetDomain(), LinkStatus::WAITING, homepageLink.GetLastLoadTime()));
        }
        else
        {
            linkStore.AddLink(Link(website.GetHomepage(), website.GetDomain(), LinkStatus::WAITING, 0));
        }

        while(true)
        {
            const auto& links = linkStore.GetBy(website.GetDomain(), LinkStatus::WAITING, 10);

            if(links.empty())
                break;


            for(const auto& link : links)
            {
                Page page = pageLoader.Load(link.GetURL());

                if(page.IsError() || page.GetStatus() < 200 || page.GetStatus() >= 300)
                {
                    linkStore.Update(Link(link.GetURL(), link.GetDomain(), LinkStatus::ERROR, time(nullptr)));
                    continue;
                }

                HTMLParser parser;    
                linkStore.Update(Link(link.GetURL(), link.GetDomain(), LinkStatus::LOADED, time(nullptr)));
            }
        }
    }
}