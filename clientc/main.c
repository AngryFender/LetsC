#include <stdio.h>
#include "../library.h"

void printDebug(const char* message){
	printf("%s\n",message);
}

void printInfo(const char* message){
	printf("%s\n", message);
}

void printWarning(const char* message){
	printf("%s\n", message);
}

void printError(const char* message){
	printf("%s\n", message);
}

void printFatal(const char* message){
	printf("%s\n", message);
}

int main(){
    printf("Starting ClientC\n");
	registerLogDebugCallback(&printDebug);
	registerLogInfoCallback(&printInfo);
	registerLogWarningCallback(&printWarning);
	registerLogErrorCallback(&printError);
	registerLogFatalCallback(&printFatal);

	Sql* handler = createSqlite("example.db");

	const int valueCount = 3;
	int types[valueCount];
	const char* values[valueCount];

	types[0] = (int) SQLITE_INTEGER;  values[0] = "33";
	types[1] = (int) SQLITE_TEXT;  values[1] = "thieves";
	types[2] = (int) SQLITE_FLOAT;  values[2] = "33.3";

	modifyQuery(handler,"INSERT INTO Test (Numbers, Words, Points) VALUES (?, ?,?);", types, values, valueCount);

	ResultRow **rows = NULL;
	int resultsCount = 0;

	retrieveQuery(handler, "SELECT Numbers, Words, Points FROM Test", &rows, &resultsCount);

	printf("Total results %d\n",resultsCount);
	for(int r = 0; r < resultsCount; ++r )
	{
		ResultRow* row = rows[r];
		char** columns = row->columns;
		const int columnsCount = row->columnsCount;
		for(int c = 0; c < columnsCount; ++c)
		{
			printf(" %s,", columns[c]);
		}
		printf("\n");
	}

	deleteResultRows(&rows, resultsCount);

	destroySqlite(handler);
    return 0;
}