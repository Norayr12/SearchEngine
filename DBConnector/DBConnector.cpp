//
// Created by norayr on 01.06.2021.
//
#include "DBConnector.hpp"

sql::Connection* DBConnector::connection;
sql::Statement* DBConnector::statement;

// Initialize connection with DB
void DBConnector::Init(const std::string& host, const std::string& user, const std::string& password)
{
    try
    {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(host, user, password);
        con->setSchema("Crawler");

        DBConnector::connection = con;
        DBConnector::statement = con->createStatement();
    }
    catch (sql::SQLException& e)
    {
        std::cout << e.what() << "\n";
    }

}

// Executes the query
sql::ResultSet* DBConnector::ExecuteQuery(const std::string& query)
{
    try
    {
        return DBConnector::statement->executeQuery(query);
    }
    catch (sql::SQLException& e)
    {
        std::cout << "EXECUTE QUERY " << e.what() << std::endl;
        return nullptr;
    }

}
