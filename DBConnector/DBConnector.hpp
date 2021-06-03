//
// Created by norayr on 01.06.2021.
//

#ifndef SEARCHENGINE__DBCONNECTOR_HPP
#define SEARCHENGINE__DBCONNECTOR_HPP

#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class DBConnector
{
public:
    static sql::Connection* connection;
    static sql::Statement* statement;

    // Initialize connection with db
    static void Init(const std::string& host, const std::string& user, const std::string& password);

    // Executes query
    static sql::ResultSet* ExecuteQuery(const std::string& query);
};

#endif //SEARCHENGINE__DBCONNECTOR_HPP
