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
  readtemperature(temperature);
  readsoc(soc);
  readchargeRate(chargeRate);
  return TRUE;
}

int main() {
   assert(batteryIsOk(BOUNDARY_VAL_TEMP1, BOUNDARY_VAL_SOC1, BOUNDARY_VAL_CHARGE_RATE1));
   assert(batteryIsOk(BOUNDARY_VAL_TEMP2, BOUNDARY_VAL_SOC2, BOUNDARY_VAL_CHARGE_RATE2)==1);
   assert(batteryIsOk(BOUNDARY_VAL_TEMP3, BOUNDARY_VAL_SOC3, BOUNDARY_VAL_CHARGE_RATE3)==1);
   return TRUE;
}
