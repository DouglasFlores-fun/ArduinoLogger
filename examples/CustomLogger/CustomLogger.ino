#include <SimpleLogger.h>

SimpleLogger logger(LOG_LEVEL_INFO);

void setup() {
  Serial.begin(9600);
  logger.enable(true);
  logger.setCallback(log);

  logger.info("System initialized");
  logger.i("Short Info message");
  logger.w("Short Warning message");
  logger.c("Short Critical message");

}

void loop() {
  // Your main code here
}

void log(int level, const char* message){
  Serial.print("level: ");
  Serial.print(level);
  Serial.print("\t message: ");
  Serial.println(message);
}
