#pragma once

#include "Gpio.h"

class Led
{
protected:
	Gpio *gpio;
public:
	Led(int gpioNumber);
	~Led();
	void turnOn();
	void turnOff();
};

