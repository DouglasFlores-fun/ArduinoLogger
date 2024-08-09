#include "Logger.h"

Logger::Logger(int level) : logLevel(level), isEnabled(true) {}

void Logger::setLogLevel(int level) {
  logLevel = level;
}

void Logger::enableLogging(bool enable) {
  isEnabled = enable;
}

void Logger::c(const char* message) {
  log(LOG_LEVEL_CRITICAL, message);
}

void Logger::w(const char* message) {
  log(LOG_LEVEL_WARNING, message);
}

void Logger::i(const char* message) {
  log(LOG_LEVEL_INFO, message);
}

void Logger::d(const char* message) {
  log(LOG_LEVEL_DEBUG, message);
}

void Logger::critical(const char* message) {
  log(LOG_LEVEL_CRITICAL, message);
}

void Logger::warning(const char* message) {
  log(LOG_LEVEL_WARNING, message);
}

void Logger::info(const char* message) {
  log(LOG_LEVEL_INFO, message);
}

void Logger::debug(const char* message) {
  log(LOG_LEVEL_DEBUG, message);
}

void Logger::log(int level, const char* message) {
  if (isEnabled && level <= logLevel) {
    printLogLevel(level);
    Serial.println(message);
  }
}

void Logger::printLogLevel(int level) {
  switch (level) {
    case LOG_LEVEL_CRITICAL: Serial.print("[CRITICAL] "); break;
    case LOG_LEVEL_WARNING:  Serial.print("[WARNING]  "); break;
    case LOG_LEVEL_INFO:     Serial.print("[INFO]     "); break;
    case LOG_LEVEL_DEBUG:    Serial.print("[DEBUG]    "); break;
    default:                 Serial.print("[UNKNOWN]  "); break;
  }
}
