#pragma once

#include "Led.h"
#include <vector>
#include "IObserver.h"

class Button : public IObserver
{
protected:
	Gpio *gpio;
public:
	virtual Button(int gpioNumber);
	virtual ~Button();
};

