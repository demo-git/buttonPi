#pragma once

#include "Button.h"
#include "Power.h"

class ButtonPower : public Button, public Observable, public IObserver
{
public:
	ButtonPower(int gpioNumber);
	~ButtonPower();
	void update(int value);
};

