#include <Arduino.h>
#include "configManager.h"
#include "dashboard.h"
#include "pumpManager.h"

void pump::begin()
{    
    // Set pump pin
    pinMode(PUMP_PIN, OUTPUT);
    // Make sure that pump is switched off by default (active low board is more common)
    digitalWrite(PUMP_PIN, HIGH); 
}

void pump::loop()
{    
    if (previous == 0 || (millis() - previous > rate))
    {
        previous = millis();
        // Conditionally start pump
        if (dash.data.moistureValue >= configManager.data.moistureThreshold 
            && dash.data.tankLevel >= configManager.data.tankLevelMin
            && millis() >= start_time+configManager.data.pumpingTime*1000+configManager.data.pumpingPause*1000
            && !dash.data.pumpingStatus)
        {
            Serial.println("Starting pump...");
            start_time = millis();
            dash.data.pumpingStatus = true;
            digitalWrite(PUMP_PIN, LOW);
            Serial.println("Started pump.");
        }
        // Conditionall stop pump
        if (millis() >= start_time+configManager.data.pumpingTime*1000 && dash.data.pumpingStatus) {
            Serial.println("Stopping pump...");
            digitalWrite(PUMP_PIN, HIGH);
            dash.data.pumpingStatus = false;
            Serial.println("Stopped pump.");
        }
    }
}

pump pumpManager;