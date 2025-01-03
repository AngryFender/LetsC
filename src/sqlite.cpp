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

Sqlite::~Sqlite()
{
    sqlite3_close(_sqlite3);
}

bool Sqlite::modQuery(const char* statement, const int* types, const char** values, int valuesCount)
{
    char* errorMessage;
    sqlite3_stmt* stmt;
    bool result = true;

    if (sqlite3_prepare_v2(_sqlite3, statement, -1, &stmt, NULL) != SQLITE_OK)
    {
        sqlite3_close(_sqlite3);
        return false;
    }

    int position = 0;
    for(int count = 0; count < valuesCount; ++count )
    {
        position = count+1;
        switch(types[count])
        {
        case SQLITE_INTEGER: sqlite3_bind_int(stmt,position,std::stoi(values[count])); break;
        case SQLITE_FLOAT: sqlite3_bind_double(stmt,position, std::stod(values[count]));break;
        case SQLITE_TEXT: sqlite3_bind_text(stmt,position, values[count],-1,SQLITE_STATIC); break;
        case SQLITE_BLOB: sqlite3_bind_blob(stmt, position,values[count],-1,SQLITE_STATIC);break;
        case SQLITE_NULL: sqlite3_bind_null(stmt,position); break;
        }
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }

    sqlite3_finalize(stmt);
    sqlite3_free(errorMessage);
    return result;
}

bool Sqlite::getQuery(const char* statement, ResultRow*** results, int resultsCount)
{
    sqlite3_stmt* stmt;

    if(sqlite3_prepare_v2(_sqlite3, statement, -1, &stmt, NULL) != SQLITE_OK)
    {
        sqlite3_close(_sqlite3);
        return false;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {

    }

    sqlite3_finalize(stmt);

    return true;
}
