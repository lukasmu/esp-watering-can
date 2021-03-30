#include <Arduino.h>
#include "LittleFS.h"

#include "WiFiManager.h"
#include "webServer.h"
#include "updater.h"
#include "configManager.h"
#include "dashboard.h"
#include "timeSync.h"
#include "waterLevelManager.h"
#include "moistureManager.h"
#include "pumpManager.h"

void setup() 
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("Booting...");
    LittleFS.begin();
    GUI.begin();
    configManager.begin(1024);
    WiFiManager.begin(configManager.data.projectName);
    timeSync.begin();
    dash.begin();
    waterLevelManager.begin();
    moistureManager.begin();
    pumpManager.begin();
    Serial.println("Booted.");
}

void loop() 
{
    WiFiManager.loop();
    waterLevelManager.loop();
    moistureManager.loop();
    pumpManager.loop();
    configManager.loop();
    updater.loop();
    dash.loop();
}