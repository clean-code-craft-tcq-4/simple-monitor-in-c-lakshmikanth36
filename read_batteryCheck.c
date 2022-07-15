#include "checker.h"

void readchargeRate(float chargeRate)
{
    if(chargeRate > CHARGE_RATE_MAX) 
    {
    #ifdef  ENG_LANGUAGE 
        printf("Charge Rate out of range!\n"); 
    #endif
    #ifdef  GERM_LANGUAGE 
        printf("Laderate außerhalb des Bereichs!\n"); 
    #endif
    }
}

void readtemperatureorsoc(float temperatureorsoc,int min_val,int max_val)
{
    if((temperatureorsoc < min_val) || (temperatureorsoc > max_val)) 
    {
        #ifdef  ENG_LANGUAGE 
            printf("Temperature/State of Charge out of range!\n");
        #endif
        #ifdef  GERM_LANGUAGE
            printf("Temperatur/Ladezustand außerhalb des Bereichs!\n");
        #endif
     }
 }

float ConvertToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void warningalert_SOC(int temperatureorsoc)
{
    if(temperatureorsoc <=SOC_MIN+4)  
    {
        #ifdef  ENG_LANGUAGE 
            printf("Approaching discharge \n");
        #endif
        #ifdef  GERM_LANGUAGE
            printf("Nähernde Entladung\n");
        #endif
    }
    else if(temperatureorsoc >= SOC_MAX-4)
    {
        #ifdef ENG_LANGUAGE 
            printf("Approaching charge-peak \n");
        #endif
        #ifdef GERM_LANGUAGE
            printf("Annäherung an die Ladungsspitze \n");
        #endif
    }     
}
