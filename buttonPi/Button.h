#pragma once

#include "Gpio.h"
#include <list>
#include "Led.h"

class Button
{
protected:
	Gpio *gpio;
	std::list<Led> leds;
public:
	Button(Gpio gpio);
	~Button();
	void addLed(Led led);
	void update(int value);
};

