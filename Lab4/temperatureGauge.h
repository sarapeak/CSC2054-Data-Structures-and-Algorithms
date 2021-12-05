#pragma once

using namespace std;

class TemperatureGauge
{
private:
	double temperature = 0, tempInC = 0, tempInF = 0;

public:
	//Constructors
	TemperatureGauge();
	TemperatureGauge(double temperature);
	//Functions
	double getTempInF();
	double getTempInC();
	void setTempInF(double temperature);
};