#ifndef CONFIG_H
#define CONFIG_H

struct configData
{
	char projectName[32];
	char projectVersion[10];
	char language[3];
	uint16_t tankDepth;
	uint8_t tankLevelNotification;
	uint8_t tankLevelMin;
	uint16_t moistureMin;
	uint16_t moistureMax;
	uint16_t moistureThreshold;
	uint8_t pumpingTime;
	uint8_t pumpingPause;
	char webhookTankNotification[255];
	char webhookTankEmpty[255];
};

extern uint32_t configVersion;
extern const configData defaults;

#endif