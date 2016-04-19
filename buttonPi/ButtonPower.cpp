#include "ButtonPower.h"



ButtonPower::ButtonPower(int gpioNumber) : Button::Button(gpioNumber)
{
	this->gpio->addObserver(this);
}


ButtonPower::~ButtonPower()
{
	this->gpio->removeObserver(this);
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
