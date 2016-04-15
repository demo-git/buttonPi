#include "ButtonLight.h"

ButtonLight::ButtonLight()
{
	this->numLed = 0;
}


ButtonLight::~ButtonLight()
{
}

void ButtonLight::update(int value)
{
	if (this->state) {
		if (this->leds.size() > this->numLed + 1) {
			this->leds.at(this->numLed).turnOff();
			this->numLed = 0;
			this->leds.at(this->numLed).turnOn();
		}
		else {
			this->leds.at(this->numLed).turnOff();
			this->numLed++;
			this->leds.at(this->numLed).turnOn();
		}
	}
}

void ButtonLight::addLed(Led led)
{
	this->leds.push_back(led);
}
