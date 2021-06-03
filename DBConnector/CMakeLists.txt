project(DBConnector)

add_library(
        DBConnector SHARED

        DBConnector.hpp
        DBConnector.cpp
)

target_link_libraries(DBConnector -lmysqlcppconn)