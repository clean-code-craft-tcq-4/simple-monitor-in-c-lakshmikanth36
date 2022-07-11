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
    if(retval!=0)
        return TRUE;
    else
        return FALSE;
}

int main() {
    int value =0;
    value=batteryIsOk(BOUNDARY_VAL_TEMP1, BOUNDARY_VAL_SOC1, BOUNDARY_VAL_CHARGE_RATE1);
    assert(value==1);
   //assert(batteryIsOk(BOUNDARY_VAL_TEMP2, BOUNDARY_VAL_SOC2, BOUNDARY_VAL_CHARGE_RATE2)==0);
   //assert(batteryIsOk(BOUNDARY_VAL_TEMP3, BOUNDARY_VAL_SOC3, BOUNDARY_VAL_CHARGE_RATE3)==0);
   return TRUE;
}
