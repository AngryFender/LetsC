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
    return 0;
}