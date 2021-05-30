project(WebsiteStore)

add_library(
        WebsiteStore SHARED

        Website.hpp
        Website.cpp

        WebsiteStore.hpp
        WebsiteStore.cpp
)

target_link_libraries(WebsiteStore)
