#ifndef SQLITE_H
#define SQLITE_H
#include <string>
#include "interface/idb.h"
#include <sqlite3.h>

class Sqlite final : public IDb{
    sqlite3* _sqlite3;

public:
    Sqlite(std::string& filename);
    Sqlite(const char* filename);
    ~Sqlite() override;

    bool modQuery(const char* statement,const int* types, const char** values,int valuesCount) override;
    bool getQuery(const char* statement,ResultRow*** results, int* resultsCount) override;
};



#endif //SQLITE_H
