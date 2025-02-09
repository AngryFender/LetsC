#ifndef LETSC_LIBRARY_H
#define LETSC_LIBRARY_H

#ifdef DLL_EXPORT
#define CALL __attribute__((visibility("default")))
#else
#define CALL
#endif

#ifdef __cplusplus
extern "C"{
#endif

enum SqlType
{
    SQLITE_INTEGER =1,
    SQLITE_FLOAT ,
    SQLITE_TEXT ,
    SQLITE_BLOB ,
    SQLITE_NULL
};


typedef struct
{
    char** columns;
    int columnsCount;
} ResultRow;

typedef struct Sql Sql;
Sql* CALL createSqlite(const char* filename);
int CALL modifyQuery(const Sql* handler, const char* statement, int* types, const char** values, const int count);
int CALL retrieveQuery(const Sql* handler, const char* statement, ResultRow*** rows, int* resultsCount);
int CALL deleteResultRows(ResultRow*** rows, const int resultsCount);
int CALL destroySqlite(Sql* handler);

typedef CALL void (*LogDebug)(const char* message);
void registerLogDebugCallback(LogDebug callback);

typedef CALL void (*LogInfo)(const char* message);
void registerLogInfoCallback(LogInfo callback);

typedef CALL void (*LogWarning)(const char* message);
void registerLogWarningCallback(LogWarning callback);

typedef CALL void (*LogError)(const char* message);
void registerLogErrorCallback(LogError callback);

typedef CALL void (*LogFatal)(const char* message);
void registerLogFatalCallback(LogFatal callback);



#ifdef __cplusplus
}
#endif

#endif //LETSC_LIBRARY_H
