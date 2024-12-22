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
    LogDebug _logDebug = nullptr;
    LogInfo _logInfo = nullptr;
    LogWarning _logWarning = nullptr;
    LogError _logError = nullptr;
    LogFatal _logFatal = nullptr;
    LogType _logType;
    std::mutex _mutex;

public:
    ~Logger() override = default;
    ILogger& operator << (const char* message) override;

    static ILogger& getInstance();
    static void setInstance(std::unique_ptr<ILogger>&& logger);
    ILogger& setLogLevel(const LogType& type) override;
    void registerDebugCallback(LogDebug logDebug) override;
    void registerInfoCallback(LogInfo logInfo) override;
    void registerWarningCallback(LogWarning logWarning) override;
    void registerErrorCallback(LogError logError) override;
    void registerFatalCallback(LogFatal logFatal) override;
private:
    Logger() = default;
};

#define Log(level) Logger::getInstance().setLogLevel(LogType::level)

#endif //LOGGER_H
