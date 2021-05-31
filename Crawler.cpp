#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "WebsiteStore/WebsiteStore.hpp"
#include "LinkStore/LinkStore.hpp"
#include "DocumentStore/DocumentStore.hpp"
#include "RequestModul/PageLoader.hpp"
#include "Parser/HTMLParser.hpp"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie();
    std::cout << "clown\n";

    WebsiteStore websiteStore;
    //DocumentStore documentStore;
    LinkStore linkStore;
    PageLoader pageLoader;

    const auto& websites = websiteStore.GetAll();

    for(const auto& website : websites)
    {

        const auto& homepageLink = linkStore.GetByUrl(website.GetHomepage());
        
        if(homepageLink.has_value())
            linkStore.Save(Link(website.GetHomepage(), website.GetDomain(), LinkStatus::WAITING, homepageLink.value().GetLastLoadTime()));
        else
            linkStore.Save(Link(website.GetHomepage(), website.GetDomain(), LinkStatus::WAITING, 0));

        while(true)
        {

            const auto& links = linkStore.GetBy(website.GetDomain(), LinkStatus::WAITING, 10);

            if(linkStore.AllLoaded())
                break;

            for(const auto& link : links)
            {
                Page page = pageLoader.Load(link.GetURL());

                if(page.GetStatus() < 200 || page.GetStatus() >= 300)
                {                    
                    linkStore.Save(Link(link.GetURL(), link.GetDomain(), LinkStatus::ERROR, time(nullptr)));
                    continue;
                }

                Parser parser(link.GetURL(), page.GetBody());
                parser.Parse();
                
                for (const std::string& u : parser.GetUrls())
                {
                    std::cout << u << std::endl;
                }

                //documentStore.AddNewDocument(Document(link.GetURL(), parser.getTitle(), parser.getDescription(), parser.getAllText()));
                //std::cout << "\n Document adds: Size - " << documentStore.GetAllDocuments().size() << "\n";
                for (const auto& newUrl : parser.GetUrls())
                {
                    if (linkStore.GetByUrl(newUrl).has_value())
                    {
                        continue;
                    }

                    linkStore.Save(Link(newUrl, link.GetDomain(), LinkStatus::WAITING, time(nullptr)));
                }
    
                linkStore.Save(Link(link.GetURL(), link.GetDomain(), LinkStatus::LOADED, time(nullptr)));


                //std::cout << "\n LINKSTORE SIZE - " << linkStore.GetAllLinks().size() << "\n";

            }
        }
        websiteStore.Update(Website(website.GetDomain(), website.GetHomepage(), time(NULL)));

    }

    std::cout << "\n\n END\n";
    return 0;
}