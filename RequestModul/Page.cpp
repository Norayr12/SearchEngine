#include "Page.hpp"

// Default constructor
Page::Page() {}

// Constructor with params
Page::Page(std::string body, int status) : body{body}, status{status} {}

// Check if "CURL ERROR"
int Page::IsError() const
{
    return 0;
}

// Getters
int Page::GetStatus() const
{
    return status;
}

const std::string& Page::GetBody() const
{
    return body;
}
//