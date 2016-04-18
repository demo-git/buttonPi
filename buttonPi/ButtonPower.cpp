#include "ButtonPower.h"



ButtonPower::ButtonPower(int gpioNumber) : Button::Button(gpioNumber)
{
}


ButtonPower::~ButtonPower()
{
}

void ButtonPower::update(int value)
{
	if (value) {
		this->notify(2);
	}
	else {
		this->notify(-1);
	}
}
