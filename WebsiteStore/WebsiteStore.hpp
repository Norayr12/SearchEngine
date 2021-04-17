#ifndef WebsiteStore_hpp
#define WebsiteStore_hpp

#include <unordered_map>
#include <vector>
#include "Website.hpp"

class WebsiteStore {
    
private: 

    // All websites
    std::unordered_map<std::string, Website> all;
    
public:

    // Default constructor
    WebsiteStore();

    // Get all websites
    std::vector<Website> GetAll() const;
    
    // Add new website to u_map
    void AddNew(const Website& website);
     
    // Updates info for the website
    void Update(const Website& website); 
    
};


#endif WebsiteStore_hpp 