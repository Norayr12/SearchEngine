project(DocumentStore)

add_library(
        DocumentStore SHARED

        Document.hpp
        Document.cpp

        DocumentStore.hpp
        DocumentStore.cpp
)

target_link_libraries(DocumentStore)