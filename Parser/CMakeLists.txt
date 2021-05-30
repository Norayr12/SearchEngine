project(Parser)

add_library(
        Parser SHARED

        HTMLParser.hpp
        HTMLParser.cpp
)

target_link_libraries(Parser -lgumbo)