#include "SimpleLogger.h"

SimpleLogger::LoggerForMicrocontroller(int level) : logLevel(level), isEnabled(true) {}

void SimpleLogger::setLogLevel(int level) {
  logLevel = level;
}

void SimpleLogger::enable(bool enable) {
  isEnabled = enable;
}

void SimpleLogger::c(const char* message) {
  log(LOG_LEVEL_CRITICAL, message);
}

void SimpleLogger::w(const char* message) {
  log(LOG_LEVEL_WARNING, message);
}

void SimpleLogger::i(const char* message) {
  log(LOG_LEVEL_INFO, message);
}

void SimpleLogger::d(const char* message) {
  log(LOG_LEVEL_DEBUG, message);
}

void SimpleLogger::critical(const char* message) {
  log(LOG_LEVEL_CRITICAL, message);
}

void SimpleLogger::warning(const char* message) {
  log(LOG_LEVEL_WARNING, message);
}

void SimpleLogger::info(const char* message) {
  log(LOG_LEVEL_INFO, message);
}

void SimpleLogger::debug(const char* message) {
  log(LOG_LEVEL_DEBUG, message);
}

void SimpleLogger::log(int level, const char* message) {
  if (isEnabled && level <= logLevel) {
    printLogLevel(level);
    Serial.println(message);
  }
}

void SimpleLogger::printLogLevel(int level) {
  switch (level) {
    case LOG_LEVEL_CRITICAL: Serial.print("[CRITICAL] "); break;
    case LOG_LEVEL_WARNING:  Serial.print("[WARNING]  "); break;
    case LOG_LEVEL_INFO:     Serial.print("[INFO]     "); break;
    case LOG_LEVEL_DEBUG:    Serial.print("[DEBUG]    "); break;
    default:                 Serial.print("[UNKNOWN]  "); break;
  }
}
