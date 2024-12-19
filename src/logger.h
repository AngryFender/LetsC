#ifndef LOGGER_H
#define LOGGER_H
#include <memory>
#include "interface/ilogger.h"
#include <mutex>
#include "../library.h"

class Logger final : public ILogger
{
    static inline std::unique_ptr<ILogger> _logger = nullptr;
    static inline std::once_flag _initFlag;
    static inline LogDebug _logDebug = nullptr;
    static inline LogInfo _logInfo = nullptr;
    static inline LogWarning _logWarning = nullptr;
    static inline LogError _logError = nullptr;
    static inline LogFatal _logFatal = nullptr;
public:
    ~Logger() override = default;
    ILogger& operator << (LogType& type) override;

    static ILogger& getInstance();
    static void setInstance(std::unique_ptr<ILogger>&& logger);
    static void registerDebugCallback(LogDebug logDebug);
    static void registerInfoCallback(LogInfo logInfo);
    static void registerWarningCallback(LogWarning logWarning);
    static void registerErrorCallback(LogError logError);
    static void registerFatalCallback(LogFatal logFatal);
private:
    Logger() = default;
};



#endif //LOGGER_H
