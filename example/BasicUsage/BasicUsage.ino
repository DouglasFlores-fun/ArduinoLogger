#include <Logger.h>

Logger logger(LOG_LEVEL_INFO);

void setup() {
  Serial.begin(9600);
  logger.enable(true);

  logger.info("System initialized");
  logger.i("Short Info message");
  logger.w("Short Warning message");
  logger.c("Short Critical message");
}

void loop() {
  // Your main code here
}
