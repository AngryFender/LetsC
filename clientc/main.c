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

	Sql* handler = createSqlite("example");

	const int valueCount = 3;
	int types[valueCount];
	const char* values[valueCount];

	types[0] = (int) 0;  values[0] = "33";
	types[1] = (int) 0;  values[1] = "thieves";
	types[2] = (int) 0;  values[2] = "33.3";

	modifyQuery(handler,"INSERT INTO Test (Numbers, Words, Points) VALUES (?, ?,?);", types, values, valueCount);
	destroySqlite(handler);



    return 0;
}