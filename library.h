#ifndef LETSC_LIBRARY_H
#define LETSC_LIBRARY_H

#ifdef DLL_EXPORT
#define CALL __attribute__((visibility("default")))
#else
#define CALL
#endif

#ifdef __cplusplus

typedef struct Sql Sql;

extern "C"{
#endif

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
