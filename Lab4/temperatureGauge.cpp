#include "temperatureGauge.h"

TemperatureGauge::TemperatureGauge()
{
	temperature = 0;   //Sets the temperature to 0
}

TemperatureGauge::TemperatureGauge(double temperature):temperature(temperature)
{
    temperature;
}

//Sets the temperature to F
double TemperatureGauge::getTempInF()
{
    //If the temp is in the range that is accepted
    if (temperature >= -30 && temperature <= 180)
    {
        tempInF = temperature;   //tempInF now equals the temp inputted
    }
    else
    {
        if (temperature >= 180)   //If the temp is greater than 180, it sets the temp to 180
        {
            temperature = 180;
            tempInF = temperature;
        }
        else if (temperature <= -30)   //If the temp is less than -30, it sets the temp to -30
        {
            temperature = -30;
            tempInF = temperature;
        }
    }
    return tempInF;
}
//Gets the temp in C
double TemperatureGauge::getTempInC()
{
	tempInC = (tempInF - 32) * 5 / 9;   //Equation to get C from F
	return tempInC;
}
//Sets the new temp to F
void TemperatureGauge::setTempInF(double newTempF)
{
    tempInF = newTempF;
    temperature = newTempF;
}
