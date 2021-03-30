#ifndef MOISTURE_SENSOR_PIN
#define MOISTURE_SENSOR_PIN A0 // analog pin to which moisture sensor is coupled
#endif

#ifndef MOISTURE_H
#define MOISTURE_H

class moisture
{
unsigned long rate = 100; // Number of milliseconds between iterations
unsigned long previous = 0; // Timestamp of last iteration

public:
    void begin();
    void loop();
};

extern moisture moistureManager;

#endif
