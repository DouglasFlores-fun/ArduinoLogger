# Simple Logger

This library provides a simple way to log messages with different severity levels, such as INFO, DEBUG, WARNING, and CRITICAL, using both short and long method names.

## Log Levels

- LOG_LEVEL_NONE
- LOG_LEVEL_CRITICAL
- LOG_LEVEL_WARNING
- LOG_LEVEL_INFO
- LOG_LEVEL_DEBUG

## Procedures

| Procedure | Description | example |
| ---- | ----- | ------ |
| c  or critical | print crital log | logger.c("This is a critical message") |
| w  or warning | print warning log | logger.w("This is a warning message")  |
| i  or info | print information log | logger.i("This is a info message")  |
| d  or debug | print debug log | logger.d("This is a debug message")  |
| enable | enable or disable log printing | logger.enable(false)  |
| setLogLevel | define log group to print | logger.setLogLevel(LOG_LEVEL_INFO)   |
| setSerial | change Serial to use as logger | logger.setSerial(Serial2)   |
| setCallback | disable serial logger and use a procedure instead |  logger.setCallback(customLog)  |

### custom callback procedure


```
...
void setup(){
    ...
    logger.setCallback(customLog)
    ...
}

void customLog(int level, const char* message){
  Serial.print("level: ");
  Serial.print(level);
  Serial.print("\t message: ");
  Serial.println(message);
}
```
