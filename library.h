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

typedef void (*LogDebug)(const char* message);
void registerLogDebugCallback(LogDebug callback);

typedef void (*LogInfo)(const char* message);
void registerLogInfoCallback(LogInfo callback);

typedef void (*LogWarning)(const char* message);
void registerLogWarningCallback(LogWarning callback);

typedef void (*LogError)(const char* message);
void registerLogErrorCallback(LogError callback);

typedef void (*LogFatal)(const char* message);
void registerLogFatalCallback(LogFatal callback);


#ifdef __cplusplus
}
#endif

#endif //LETSC_LIBRARY_H
