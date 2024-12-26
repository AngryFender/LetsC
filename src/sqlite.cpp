#include "sqlite.h"
#include "logger.h"

Sqlite::Sqlite(std::string& filename):_sqlite3(nullptr)
{
    Log(DEBUG)<<"Opening Sqlite db";
    int result = sqlite3_open(filename.c_str(),&_sqlite3);

    if(_sqlite3 == nullptr)
    {
        Log(ERROR)<<"Failed to open Sqlite db "<<filename.c_str();
    }

}

bool Sqlite::modQuery(const char* statement, const int* types, const char** values, int valuesCount)
{
    return false;
}

bool Sqlite::getQuery(const char* statement, ResultRow*** results, int resultsCount)
{
    return false;
}
