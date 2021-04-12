#include <Arduino.h>
#include "config.h"

uint32_t configVersion = 387598215; //generated identifier to compare config with EEPROM

const configData defaults PROGMEM =
{
	"ESP 8266 Watering Can",
	"0.2.1",
	"en",
	200,
	50,
	20,
	300,
	800,
	500,
	3,
	30,
	"",
	""
};