#include "Led.h"



Led::Led(int gpioNumber)
{
	this->gpio = Gpio::getInstance(gpioNumber, false);
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
