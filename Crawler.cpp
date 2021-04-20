#include <iostream>
#include <string>
#include <vector>
#include "WebsiteStore/WebsiteStore.hpp"
#include "LinkStore/LinkStore.hpp"
#include "DocumentStore/DocumentStore.hpp"
#include "RequestModul/PageLoader.hpp"
#include "Parser/HTMLParser.hpp"

int main()
{
    
    WebsiteStore websiteStore;
    DocumentStore documentStore;
    LinkStore linkStore;
    PageLoader pageLoader;
    
    
    const auto& websites = websiteStore.GetAll();
    // size == 1 (OK)
    
    for(const auto& website : websites)
    {
        
        std::cout << website.GetHomepage();
        
        const auto& homepageLink = linkStore.GetByUrl(website.GetHomepage());
        
        if(homepageLink.GetURL() != "")
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
            std::cout << links.size();
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

                GumboOutput* output = gumbo_parse(page.GetBody().c_str());
                Document document = HTMLParser::GetDocument(output->root);
                documentStore.AddNewDocument(document);

                std::vector<std::string> extractedLinks;
                HTMLParser::SearchLinks(output->root, extractedLinks);
                gumbo_destroy_output(&kGumboDefaultOptions, output);

                for(int i = 0; i < extractedLinks.size(); ++i)
                {
                   // std::cout << extractedLinks[i] << "\n";
                }

                for(int i = 0; i < extractedLinks.size(); ++i)
                {
                    if(linkStore.ContainsLink(extractedLinks[i]))                   
                        continue;  

                     
                    linkStore.AddLink(Link(extractedLinks[i], link.GetDomain(), LinkStatus::WAITING, time(nullptr)));
                }
    
                linkStore.Update(Link(link.GetURL(), link.GetDomain(), LinkStatus::LOADED, time(nullptr)));

                //std::cout << "DOCUMENTS: " << (documentStore.GetAllDocuments()).size();
            }
        }
        
        websiteStore.Update(Website(website.GetDomain(), website.GetHomepage(), time(NULL)));
    }
    return 0;
}