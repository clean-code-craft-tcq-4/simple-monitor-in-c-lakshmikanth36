#include "checker.h"

float readtemperature(float temperature)
{
    if((temperature < TEMP_MIN) || (temperature > TEMP_MAX))
    {
        printf("Temperature out of range!\n");
        return TRUE;
    }
    else
        return FALSE;
}

float readsoc(float soc)
{
    if(soc < SOC_MIN || soc > SOC_MAX)
    {
        printf("State of Charge out of range!\n");
        return TRUE;
    }
    else
        return FALSE;
}

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

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int retval=0;
    retval=readtemperature(temperature);
    retval=readsoc(soc);
    retval=readchargeRate(chargeRate);
    if(retval)
        return TRUE;
    else
        return FALSE;
}

int main() {
   assert(batteryIsOk(BOUNDARY_VAL_TEMP2, BOUNDARY_VAL_SOC2, BOUNDARY_VAL_CHARGE_RATE2)==1);
   //assert(batteryIsOk(BOUNDARY_VAL_TEMP3, BOUNDARY_VAL_SOC3, BOUNDARY_VAL_CHARGE_RATE3)==1);
   return TRUE;
}
