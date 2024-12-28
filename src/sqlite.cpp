#include "sqlite.h"
#include "logger.h"

int Sqlite::callBack(void* unused, int count, char** data, char** columns)
{
    return 0;
}

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
    char* errorMessage;
    sqlite3_exec(_sqlite3, statement, callBack,nullptr,&errorMessage);


    sqlite3_free(errorMessage);
    return false;
}

bool Sqlite::getQuery(const char* statement, ResultRow*** results, int resultsCount)
{
    return false;
}
