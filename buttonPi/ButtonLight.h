#pragma once

#include <vector>
#include "Led.h"
#include "Button.h"
#include "Power.h"

class ButtonLight : public Button, public Power, public IObserver
{
protected:
	int numLed = 0;
	std::vector<Led> leds;
public:
	ButtonLight(int gpioNumber);
	~ButtonLight();

	void update(int value);
	void addLed(Led led);
};

