#ifndef PUMP_PIN
#define PUMP_PIN D5 // pin that triggers the motor (relay)
#endif

#ifndef PUMP_H
#define PUMP_H

class pump
{
unsigned long rate = 100; // Number of milliseconds between iterations
unsigned long previous = 0; // Timestamp of last iteration

unsigned long start_time = 0; // The last time the pump was started

public:
    void begin();
    void loop();
};

extern pump pumpManager;

#endif
