#include "Button.h"

Button::~Button()
{
}

Button::Button(int gpioNumber)
{
    this->gpio = Gpio::getInstance(gpioNumber, true);
}

