#ifndef IDB_H
#define IDB_H

struct ResultRow
{
    int columnCount;
    char** columns;
};

class IDb
{
public:
    virtual ~ IDb() = default;
    virtual bool modQuery(const char* statement,const int* types, const char** values,int valuesCount) = 0;
    virtual bool getQuery(const char* statement,ResultRow*** results, int resultsCount) = 0;
};

#endif //IDB_H
