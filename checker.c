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
    int return_val=0;
    return_val=readtemperature(temperature);
    printf("return value of Temp:%d",return_val);
    return_val=readsoc(soc);
    printf("return value of soc:%d",return_val);
    return_val=readchargeRate(chargeRate);
    printf("return value of chargerate:%d",return_val);
    if(return_val!=0)
        return TRUE;
    else
        return FALSE;
}

int main() {
   assert(batteryIsOk(BOUNDARY_VAL_TEMP1, BOUNDARY_VAL_SOC1, BOUNDARY_VAL_CHARGE_RATE1));
   //assert(batteryIsOk(BOUNDARY_VAL_TEMP2, BOUNDARY_VAL_SOC2, BOUNDARY_VAL_CHARGE_RATE2)==0);
   //assert(batteryIsOk(BOUNDARY_VAL_TEMP3, BOUNDARY_VAL_SOC3, BOUNDARY_VAL_CHARGE_RATE3)==0);
   return TRUE;
}
