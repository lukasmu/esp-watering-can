#ifndef ULTRASONIC_TRIGGER_PIN
#define ULTRASONIC_TRIGGER_PIN D7 // trigger pin used for ultrasonic sensor
#endif
#ifndef ULTRASONIC_ECHO_PIN
#define ULTRASONIC_ECHO_PIN D6 // echo pin used for ultrasonic sensor
#endif

#ifndef WATER_LEVEL_H
#define WATER_LEVEL_H

class waterLevel
{
unsigned long rate = 1000; // Number of milliseconds between iterations
unsigned long previous = 0; // Timestamp of last iteration

bool notification_webhook_called = false; // Indicates if the tank notification webhook has already been called
bool empty_webhook_called = false; // Indicates if the tank empty webhook has already been called

public:
    void begin();
    void loop();
};

extern waterLevel waterLevelManager;

#endif
