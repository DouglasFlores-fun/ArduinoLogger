#include "SimpleLogger.h"

SimpleLogger::SimpleLogger(int level) : _logLevel(level), _isEnabled(true), _serial(&Serial), _callback(nullptr) {}

void SimpleLogger::setLogLevel(int level) {
  _logLevel = level;
}

void SimpleLogger::enable(bool enable) {
  _isEnabled = enable;
}

void SimpleLogger::setSerial(Stream &serialPort){
  _serial = &serialPort;
}

void SimpleLogger::setCallback(void (*callbackFunction)(int, const char*)) {
    _callback = callbackFunction;
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
  if (_isEnabled && level <= _logLevel) {
    if(_callback){
      _callback(level, message);
    }else{
      printLogLevel(level);
      _serial->println(message);
    }
    
  }
}

void SimpleLogger::printLogLevel(int level) {
  switch (level) {
    case LOG_LEVEL_CRITICAL: _serial->print("[CRITICAL] "); break;
    case LOG_LEVEL_WARNING:  _serial->print("[WARNING]  "); break;
    case LOG_LEVEL_INFO:     _serial->print("[INFO]     "); break;
    case LOG_LEVEL_DEBUG:    _serial->print("[DEBUG]    "); break;
    default:                 _serial->print("[UNKNOWN]  "); break;
  }
}
