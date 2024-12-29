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
    sqlite3_stmt* stmt;
    bool result = true;

    if (sqlite3_prepare_v2(_sqlite3, statement, -1, &stmt, NULL) != SQLITE_OK) {
        sqlite3_close(_sqlite3);
        return false;
    }

    for(int count = 0; count < valuesCount; ++count )
    {
        //switch(types)
        //sqlite3_bind_text(stmt, ...);
        //sqlite3_bind_int(stmt, ...);
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }

    sqlite3_free(errorMessage);
    return result;
}

bool Sqlite::getQuery(const char* statement, ResultRow*** results, int resultsCount)
{
    return false;
}
