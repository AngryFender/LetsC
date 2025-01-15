#include "library.h"
#include "src/logger.h"
#include "src/sqlite.h"

struct Sql
{
   IDb * db;
};

Sql * createSqlite(const char* filename)
{
   Sql * handler = new Sql;
   handler->db = new Sqlite(filename);
   return handler;
}

int modifyQuery(const Sql* handler, const char* statement, int* types, const char** values, const int count)
{
   if(handler == nullptr || !handler->db->modQuery(statement,types,values,count))
   {
      return 0;
   }
   return 1;
}

int retrieveQuery(const Sql* handler, const char* statement, ResultRow*** rows, int* resultsCount)
{
   if(handler == nullptr || !handler->db->getQuery(statement, rows, resultsCount))
   {
      return 0;
   }
   return 1;
}

int deleteResultRows(ResultRow*** rows, const int resultsCount)
{
   if(rows == nullptr)
   {
      return 0;
   }

   ResultRow** ptrRows = *rows;
   for(int r = 0; r < resultsCount; ++r)
   {
      ResultRow* row = ptrRows[r];
      const int columnCount = row->columnsCount;
      for(int c = 0; c < columnCount; ++c)
      {
         free(row->columns[c]);
      }
      delete[] row->columns;
      delete row;
   }

   delete[] ptrRows;
   *rows = nullptr;

   return 1;
}

int destroySqlite(Sql * handler)
{
   if(handler == nullptr)
   {
      return 0;
   }
   delete handler->db;
   delete handler;
   return 1;
}

void registerLogDebugCallback(const LogDebug callback)
{
   Logger::getInstance().registerDebugCallback(callback);
}

void registerLogInfoCallback(const LogInfo callback)
{
   Logger::getInstance().registerInfoCallback(callback);
}

void registerLogWarningCallback(const LogWarning callback)
{
   Logger::getInstance().registerWarningCallback(callback);
}

void registerLogErrorCallback(const LogError callback)
{
   Logger::getInstance().registerErrorCallback(callback);
}

void registerLogFatalCallback(const LogFatal callback)
{
   Logger::getInstance().registerFatalCallback(callback);
}


