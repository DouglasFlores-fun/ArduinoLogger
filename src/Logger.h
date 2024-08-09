#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

#define LOG_LEVEL_NONE     0
#define LOG_LEVEL_CRITICAL 1
#define LOG_LEVEL_WARNING  2
#define LOG_LEVEL_INFO     3
#define LOG_LEVEL_DEBUG    4

class Logger {
  public:
    Logger(int level);

    void setLogLevel(int level);
    void enableLogging(bool enable);

    // Short name methods
    void c(const char* message);
    void w(const char* message);
    void i(const char* message);
    void d(const char* message);

    // Long name methods
    void critical(const char* message);
    void warning(const char* message);
    void info(const char* message);
    void debug(const char* message);

  private:
    int logLevel;
    bool isEnabled;

    void log(int level, const char* message);
    void printLogLevel(int level);
};

#endif // LOGGER_H
