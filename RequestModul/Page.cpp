#include "Page.hpp"

Page::Page(std::string body, int status) : body{body}, status{status} {}

Page::Page() {}

int Page::IsError() const
{
    return 0;
}

int Page::GetStatus() const
{
    return status;
}

const std::string& Page::GetBody() const
{
    return body;
}