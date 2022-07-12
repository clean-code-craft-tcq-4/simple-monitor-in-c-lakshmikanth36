#include "checker.h"

float readchargeRate(float chargeRate)
{
    if(chargeRate > CHARGE_RATE_MAX)
    {
        printf("Charge Rate out of range!\n");
        return TRUE;
    }
    else
        return FALSE;
}

float readtemperature_soc(float temperature,float soc)
{
    if((temperature < TEMP_MIN) || (temperature > TEMP_MAX))
    {
        printf("Temperature out of range!\n");
        return TRUE;
    }
    else if(soc < SOC_MIN || soc > SOC_MAX)
    {
        printf("State of Charge out of range!\n");
        return TRUE;
    }
    else
        return FALSE;
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int retval=0;
    retval=readtemperature_soc(temperature,soc);
    retval=readchargeRate(chargeRate);
    if(retval!=0)
        return TRUE;
    else
        return FALSE;
}

int main() {
   assert(batteryIsOk(BOUNDARY_VAL_TEMP2, BOUNDARY_VAL_SOC2, BOUNDARY_VAL_CHARGE_RATE2));
   assert(batteryIsOk(44,79,0.7)==0);
   assert(batteryIsOk(25,70,0.6)==0);
   return TRUE;
}
