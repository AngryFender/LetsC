#ifndef LOGGER_H
#define LOGGER_H
#include <memory>
#include "interface/ilogger.h"
#include <mutex>

class Logger: public ILogger
{
    static std::unique_ptr<ILogger> _logger;
    static std::once_flag _initFlag;
public:
    ~Logger() override = default;
    ILogger& operator << (LogType& type) override;

    static ILogger& getInstance();
    static void setInstance(std::unique_ptr<ILogger>&& logger);

private:
    Logger();
};



#endif //LOGGER_H
