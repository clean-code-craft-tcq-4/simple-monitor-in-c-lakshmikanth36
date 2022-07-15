#include "checker.h"

int batteryIsOk(float temperature, float soc,float chargeRate) {
    int conversion_temperature  = 0;
    conversion_temperature = ConvertToCelcius(temperature);
    readtemperatureorsoc(conversion_temperature,TEMP_MIN,TEMP_MAX);
    readtemperatureorsoc(soc,SOC_MIN,SOC_MAX);
    warningalert_SOC(soc);
    readtemperatureorsoc(chargeRate,CHARGE_RATE_MIN,CHARGE_RATE_MAX);
return 0;
}

int main() {
     unittest_batterycheck();
 return 0;
}
