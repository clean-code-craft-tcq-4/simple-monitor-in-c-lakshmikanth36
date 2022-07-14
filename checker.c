#include "checker.h"

void readchargeRate(float chargeRate)
{
    if(chargeRate > CHARGE_RATE_MAX)
        printf("Charge Rate out of range!\n");
}

void readtemperatureorsoc(float temperatureorsoc,int min_val,int max_val)
{
    if((temperatureorsoc < min_val) || (temperatureorsoc > max_val))
        printf("Temperature/State of Charge out of range!\n");
 }

int batteryIsOk(float temperature, float soc,float chargeRate) {
    readtemperatureorsoc(temperature,TEMP_MIN,TEMP_MAX);
    readtemperatureorsoc(soc,SOC_MIN,SOC_MAX);
    warningalert_SOC(soc);
    readchargeRate(chargeRate);
return 0;
}

void warningalert_SOC(int temperatureorsoc)
{
    if(temperatureorsoc <=SOC_MIN+4)
        printf("Warning: Approaching discharge \n");
    else if(temperatureorsoc >= SOC_MAX-4)
        printf("Warning: Approaching charge-peak \n");
}

int main() {
     assert(batteryIsOk(0,20,0.0)==0);
     assert(batteryIsOk(5,25,0.1)==0);
     assert(batteryIsOk(25,50,0.4)==0);
     assert(batteryIsOk(40,75,0.7)==0);
     assert(!batteryIsOk(45,80,0.8));
     assert(!batteryIsOk(50,85,0.9));
     assert(!batteryIsOk(100,81,0.9));
     assert(!batteryIsOk(400,81,0.9));
     assert(!batteryIsOk(500,81,0.9));
     assert(!batteryIsOk(1,19,0.7));
     assert(batteryIsOk(25,21,0.7)==0);
     assert(batteryIsOk(25,22,0.7)==0);
     assert(batteryIsOk(25,23,0.7)==0);
     assert(batteryIsOk(25,24,0.7)==0);
     assert(batteryIsOk(25,25,0.7)==0);
     assert(batteryIsOk(25,76,0.7)==0);
     assert(batteryIsOk(25,77,0.7)==0);
     assert(batteryIsOk(25,78,0.7)==0);
     assert(batteryIsOk(25,79,0.7)==0);
     assert(batteryIsOk(25,80,0.7)==0);
 return 0;
}
