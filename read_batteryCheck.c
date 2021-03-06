#include "checker.h"

void readtemperatureorsoc(float temperatureorsoc,int min_val,int max_val)
{
    if((temperatureorsoc < min_val) || (temperatureorsoc > max_val)) 
            printf("Temperature/State of Charge/Charge Rate out of range!\n");
 }

float ConvertToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void warningalert_SOC(int temperatureorsoc)
{
    if(temperatureorsoc <=SOC_MIN+4) 
            printf("Approaching discharge \n");
    else if(temperatureorsoc >= SOC_MAX-4)
            printf("Approaching charge-peak \n");
}
