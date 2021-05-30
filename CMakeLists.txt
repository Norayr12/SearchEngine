cmake_minimum_required(VERSION 3.16)
project(SearchEngine_ VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories("RequestModul")
include_directories("Parser")
include_directories("LinkStore")
include_directories("WebsiteStore")
include_directories("DocumentStore")

add_executable(${PROJECT_NAME} Crawler.cpp)

add_subdirectory(RequestModul)
add_subdirectory(Parser)
add_subdirectory(LinkStore)
add_subdirectory(WebsiteStore)
add_subdirectory(DocumentStore)

set_target_properties(RequestModul PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/RequestModul/libRequestModul.so"
        )

set_target_properties(Parser PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/Parser/libParser.so"
        )

set_target_properties(LinkStore PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkStore/libLinkStore.so"
        )

set_target_properties(WebsiteStore PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/WebsiteStore/libWebsiteStore.so"
        )

set_target_properties(DocumentStore PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/DocumentStore/libDocumentStore.so"
        )

target_link_libraries(${PROJECT_NAME} RequestModul Parser LinkStore WebsiteStore DocumentStore)