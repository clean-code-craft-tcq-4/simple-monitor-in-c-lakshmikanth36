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
    readchargeRate(chargeRate);
return 0;
}
int main() {
     assert(batteryIsOk(0,20,0.0)==0);
     assert(batteryIsOk(5,25,0.1)==0);
     assert(batteryIsOk(25,50,0.4)==0);
     assert(batteryIsOk(40,75,0.7)==0);
     
 return 0;
}
