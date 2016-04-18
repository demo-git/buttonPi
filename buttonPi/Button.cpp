#include "Button.h"

Button::~Button()
{
    this->gpio->removeObserver(this);
}

Button::Button(int gpioNumber)
{
    this->gpio = Gpio::getInstance(gpioNumber, true);
    this->gpio->addObserver(this);
}

