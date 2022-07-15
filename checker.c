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

float ConvertToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

int batteryIsOk(float temperature, float soc,float chargeRate) {
    int conversion_temperature  = 0;
    conversion_temperature = ConvertToCelcius(temperature);
    readtemperatureorsoc(conversion_temperature,TEMP_MIN,TEMP_MAX);
    readtemperatureorsoc(soc,SOC_MIN,SOC_MAX);
    warningalert_SOC(soc);
    readchargeRate(chargeRate);
return 0;
}

void warningalert_SOC(int temperatureorsoc)
{
    if(temperatureorsoc <=SOC_MIN+4)  
        printf("Approaching discharge \n");
    else if(temperatureorsoc >= SOC_MAX-4)
        printf("Approaching charge-peak \n");
}

int main() {
     unittest_batterycheck();
 return 0;
}
