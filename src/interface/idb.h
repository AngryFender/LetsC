#ifndef IDB_H
#define IDB_H

class IDb
{
public:
    virtual ~ IDb() = default;
    virtual bool modQuery(const char* statement,const int* types, const char** values,int valuesCount) = 0;
};

#endif //IDB_H
