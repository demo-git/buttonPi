#include "ButtonStop.h"

ButtonStop::ButtonStop(int gpioNumber) : Button::Button(gpioNumber)
{
    this->gpio->addObserver(this);
}


ButtonStop::~ButtonStop()
{
    this->gpio->removeObserver(this);
}

void ButtonStop::update(int value)
{
    if (value == 1) {
        this->notify(value);
    }
}
