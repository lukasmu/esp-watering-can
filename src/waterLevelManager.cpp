#include <Arduino.h>
#include "configManager.h"
#include "dashboard.h"
#include "fetch.h"
#include "waterLevelManager.h"

void waterLevel::begin()
{    
    // Set sensor pins
    pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
    pinMode(ULTRASONIC_ECHO_PIN, INPUT);
}

void waterLevel::loop()
{    
    if (previous == 0 || (millis() - previous > rate))
    {
        previous = millis();
        // Determine the time (in milliseconds) that is needed for a soundwave for a roundtrip between sensor and water
        digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
        delayMicroseconds(2);
        digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
        unsigned long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
        // Calculate the distance (in millimeters) based on the speed of sound in air
        unsigned int distance = duration*0.34/2;
        // Then calculate water level (again in millimeters)
        dash.data.tankLevel = configManager.data.tankDepth-distance;
        // Finally do checks and call/reset webhooks when required
        if(dash.data.tankLevel <= configManager.data.tankLevelNotification && !notification_webhook_called && strlen(configManager.data.webhookTankNotification) > 3) 
        {
            Serial.println("Calling notification webhook...");
            fetch.GET(configManager.data.webhookTankNotification);
            while (fetch.busy())
            {
                if (fetch.available())
                {
                    Serial.write(fetch.read());
                }
            }
            fetch.clean();
            notification_webhook_called = true;
            Serial.println("\n");
            Serial.println("Called notification webhook.");
        }
        if (dash.data.tankLevel > configManager.data.tankLevelNotification && notification_webhook_called) 
        {
            Serial.println("Resetting notification webhook...");
            notification_webhook_called = false;
            Serial.println("Resetted notification webhook.");
        }
        if(dash.data.tankLevel <= configManager.data.tankLevelMin && !empty_webhook_called && strlen(configManager.data.webhookTankEmpty) > 3) 
        {
            Serial.println("Calling empty webhook...");
            fetch.GET(configManager.data.webhookTankEmpty);
            while (fetch.busy())
            {
                if (fetch.available())
                {
                    Serial.write(fetch.read());
                }
            }
            fetch.clean();
            empty_webhook_called = true;
            Serial.println();
            Serial.println("Called empty webhook.");
        }
        if (dash.data.tankLevel > configManager.data.tankLevelMin && empty_webhook_called) 
        {
            Serial.println("Resetting empty webhook...");
            empty_webhook_called = false;
            Serial.println("Resetted empty webhook.");
        }
    }
}

waterLevel waterLevelManager;