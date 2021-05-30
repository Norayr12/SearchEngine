project(LinkStore)

add_library(
        LinkStore SHARED

        Link.hpp
        Link.cpp

        LinkStatus.hpp

        LinkStore.hpp
        LinkStore.cpp
)

target_link_libraries(LinkStore)