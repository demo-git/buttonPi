#pragma once

#include <vector>
#include "Led.h"
#include "Button.h"
#include "Power.h"

class ButtonLight : public Button, public Power
{
protected:
	int numLed;
	std::vector<Led> leds;
public:
	ButtonLight();
	~ButtonLight();
	void update(int value);
	void addLed(Led led);
};

