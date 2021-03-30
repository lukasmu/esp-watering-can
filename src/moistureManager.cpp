#include <Arduino.h>
#include "configManager.h"
#include "dashboard.h"
#include "moistureManager.h"

void moisture::begin()
{    
    // Silence is golden
}

void moisture::loop()
{    
    if (previous == 0 || (millis() - previous > rate))
    {
        previous = millis();
        // Determine moisture (absolute)
        dash.data.moistureValue = analogRead(A0);
        // Determine moisture (relative)
        dash.data.moistureValuePercent = (int)((1.0-(dash.data.moistureValue-configManager.data.moistureMin)/(configManager.data.moistureMax-(float)configManager.data.moistureMin))*100.0);
    }
}

moisture moistureManager;