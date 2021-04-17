#ifndef PAGE_LOADER_HPP
#define PAGE_LOADER_HPP

#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include "Page.hpp"

class PageLoader {
public:
    
    PageLoader();
  
    Page Load(const std::string& url);
};
#endif