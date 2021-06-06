//
// Created by norayr on 01.06.2021.
//

#ifndef SEARCHENGINE__DBCONNECTOR_HPP
#define SEARCHENGINE__DBCONNECTOR_HPP

#include <iostream>
#include <vector>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class DBConnector
{
public:
    static sql::Connection* connection;
    static sql::Statement* statement;
    static sql::PreparedStatement* preparedStatement;

    // Initialize connection with db
    static void Init(const std::string& host, const std::string& user, const std::string& password);

    // Executes query
    static sql::ResultSet* ExecuteQuery(const std::string& query);

    static  sql::ResultSet* ExecuteQuery(const std::string& query, std::vector<std::string>& values);
};

#endif //SEARCHENGINE__DBCONNECTOR_HPP
