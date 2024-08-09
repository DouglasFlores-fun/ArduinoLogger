#include <SimpleLogger.h>
#include <SoftwareSerial.h>

SimpleLogger logger(LOG_LEVEL_INFO);
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(4800);
  logger.enable(true);
  logger.setSerial(mySerial);

  logger.info("System initialized");
  logger.i("Short Info message");
  logger.w("Short Warning message");
  logger.c("Short Critical message");
}

void loop() {
  // Your main code here
}
