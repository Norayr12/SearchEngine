#ifndef CURLPP
#define CURLPP
#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

class Page {
private:
    std::string body;
    int status;

public:
    Page();
    Page(std::string body, int status);
    int IsError() const;
    int GetStatus() const;
    const std::string& GetBody() const;
};

#endif