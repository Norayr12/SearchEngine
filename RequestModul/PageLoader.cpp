#include "PageLoader.hpp"
#include "Page.cpp"
#include "HTMLParser.cpp"

std::string res;

PageLoader::PageLoader() {}

size_t GetData (char* buffer, size_t size, size_t n, void* _)
{
    size_t bytes = size * n;   
    for (size_t i = 0; i < bytes; i++)
    {
        res += buffer[i];
    }   
    return bytes;
}

Page PageLoader::Load(const std::string& url)
{
    res = "";
    CURL* curl = curl_easy_init();
    if(curl == nullptr)
    {
        std::cerr << "cURL init failed";
        return Page();
    }   
    
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetData);
    
    CURLcode result = curl_easy_perform(curl);   
    
    if (result != CURLE_OK)
        std::cerr << "Request failed!";
    
    long responseCode;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);

    curl_easy_cleanup(curl);  
    return Page(res, responseCode);
}

int main()
{
    PageLoader request;
    Page response = request.Load("https://ru.wikipedia.org/wiki/Заглавная_страница");
    //std::cout << "Response status: " << response.GetStatus() << "\nResponse body: " << response.GetBody();
    std::vector<std::string> links, documents;

    GumboOutput* output = gumbo_parse(response.GetBody().c_str());
    HTMLParser::SearchLinks(output->root, links);
    documents.push_back(HTMLParser::SearchText(output->root));
    
    std::cout << "LINKS:";
    for(int i = 0; i < links.size(); ++i)
        std::cout << links[i] << "\n";

    std::cout << "DOCUMENTS:";
    for(int i = 0; i < documents.size(); ++i)
        std::cout << documents[i];
    gumbo_destroy_output(&kGumboDefaultOptions, output);
}