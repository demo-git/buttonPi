#pragma once

#include "Gpio.h"
#include "IObserver.h"

class Button
{
protected:
	Gpio *gpio;
public:
	Button(int gpioNumber);
	virtual ~Button();
};

