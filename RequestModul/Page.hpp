#ifndef CURLPP
#define CURLPP
#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

class Page {
private:

    // Body of Page: all text
    std::string body;

    // Returned status after loading : ( #404 )
    int status;

public:

    // Default constructor
    Page();

    // Constructor with params
    Page(std::string body, int status);

    // Getters
    int GetStatus() const;
    const std::string& GetBody() const;
    //
};

#endif