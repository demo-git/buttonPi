#pragma once

#include "Gpio.h"

class Led
{
protected:
	Gpio *gpio;
public:
	Led(Gpio gpio);
	~Led();
	void turnOn();
	void turnOff();
};

