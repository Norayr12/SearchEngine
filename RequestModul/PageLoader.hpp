#ifndef PAGE_LOADER_HPP
#define PAGE_LOADER_HPP

#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include "Page.hpp"

class PageLoader {
public:
    
    // Default constructor
    PageLoader();
  
    // Get PAGE instance by URI
    Page Load(const std::string& url);
};
#endif