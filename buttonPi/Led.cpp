#include "Led.h"



Led::Led(Gpio gpio)
{
	this->gpio = &gpio;
}


Led::~Led()
{
}

void Led::turnOn()
{
	this->gpio->setValue(1);
}

void Led::turnOff()
{
	this->gpio->setValue(0);
}
