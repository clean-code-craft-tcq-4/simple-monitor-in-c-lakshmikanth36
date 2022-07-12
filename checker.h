#include <stdio.h>
#include <assert.h>
#define SOC_MIN 20
#define SOC_MAX 80
#define TEMP_MIN 0
#define TEMP_MAX 45
#define CHARGE_RATE_MAX 0.8
#define BOUNDARY_VAL_TEMP1 45
#define BOUNDARY_VAL_TEMP2 46
#define BOUNDARY_VAL_TEMP3 -1
#define BOUNDARY_VAL_SOC1 80
#define BOUNDARY_VAL_SOC2 81
#define BOUNDARY_VAL_SOC3 19
#define BOUNDARY_VAL_CHARGE_RATE1 0.7
#define BOUNDARY_VAL_CHARGE_RATE2 0.8
#define BOUNDARY_VAL_CHARGE_RATE3 -0.1
#define TRUE 0
#define FALSE 1
int batteryIsOk(float temperature, float soc, float chargeRate);
float readchargeRate(float chargeRate);
float readsoc(float soc);
float readtemperature(float temperature);
float readtemperature_soc(float temperature,float soc);
