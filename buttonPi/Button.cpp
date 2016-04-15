#include "Button.h"



Button::Button(Gpio gpio)
{
	this->gpio = &gpio;
}


Button::~Button()
{
}

void Button::addLed(Led led)
{
}

void Button::update(int value)
{
}
