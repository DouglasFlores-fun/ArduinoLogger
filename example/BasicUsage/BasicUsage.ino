#include <Logger.h>

Logger log(LOG_LEVEL_INFO);

void setup() {
  Serial.begin(9600);
  log.enableLogging(true);

  log.logInfo("System initialized");
  log.i("Short Info message");
  log.w("Short Warning message");
  log.c("Short Critical message");
}

void loop() {
  // Your main code here
}
