project(RequestModul)

add_library(
        RequestModul SHARED

        Page.hpp
        Page.cpp

        PageLoader.hpp
        PageLoader.cpp
)

target_link_libraries(RequestModul -lcurl)