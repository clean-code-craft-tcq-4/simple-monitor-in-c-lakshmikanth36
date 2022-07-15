#include "checker.h"

void readchargeRate(float chargeRate)
{
    if(chargeRate > CHARGE_RATE_MAX)
    {
    #ifdef ENG_LANGUAGE    
        printf("Charge Rate out of range!\n");
    #endif
    #ifdef GERM_LANGUAGE 
         printf("Laderate außerhalb des zulässigen Bereichs!\n");
    }
}

void readtemperatureorsoc(float temperatureorsoc,int min_val,int max_val)
{
    if((temperatureorsoc < min_val) || (temperatureorsoc > max_val))
    {
    #ifdef ENG_LANGUAGE     
        printf("Temperature/State of Charge out of range!\n");
    #endif
    #ifdef GERM_LANGUAGE
        printf("Temperatur/Ladezustand außerhalb des Bereichs!\n");
    }
 }

float ConvertToCelcius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

int batteryIsOk(float temperature, float soc,float chargeRate) {
    conversion_temperature = ConvertToCelcius(temperature);
    readtemperatureorsoc(conversion_temperature,TEMP_MIN,TEMP_MAX);
    readtemperatureorsoc(soc,SOC_MIN,SOC_MAX);
    warningalert_SOC(soc);
    readchargeRate(chargeRate);
return 0;
}

void warningalert_SOC(int temperatureorsoc)
{
    if(temperatureorsoc <=SOC_MIN+4) {
     #ifdef ENG_LANGUAGE     
        printf("Approaching discharge \n");
     #endif 
     #ifdef GERM_LANGUAGE   
        printf("Entladung nähert sich \n");
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
