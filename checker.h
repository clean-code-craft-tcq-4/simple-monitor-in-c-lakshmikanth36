#include <stdio.h>
#include <assert.h>
#define SOC_MIN 20
#define SOC_MAX 80
#define TEMP_MIN 0
#define TEMP_MAX 45
#define CHARGE_RATE_MIN 0.0
#define CHARGE_RATE_MAX 0.8
#define ENG_LANGUAGE English
#define GERM_LANGUAGE Englisch
int batteryIsOk(float temperature, float soc, float chargeRate);
void readtemperatureorsoc(float temperatureorsoc,int min_val,int max_val);
void warningalert_SOC(int temperatureorsoc);
float ConvertToCelcius(float farenheit);
void unittest_batterycheck();
