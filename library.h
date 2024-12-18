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

typedef void (*LogDebug)(char** message);
void registerLogDebugCallback(LogDebug callback);

typedef void (*LogInfo)(char** message);
void registerLogInfoCallback(LogInfo callback);

typedef void (*LogWarning)(char** message);
void registerLogInfoCallback(LogWarning callback);

typedef void (*LogError)(char** message);
void registerLogInfoCallback(LogError callback);

typedef void (*LogFatal)(char** message);
void registerLogInfoCallback(LogFatal callback);

CALL void hello();



#ifdef __cplusplus
}
#endif

#endif //LETSC_LIBRARY_H
