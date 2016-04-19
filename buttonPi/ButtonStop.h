#pragma once

#include "Button.h"

class ButtonStop : public Button, public Observable, public IObserver
{
public:
	ButtonStop(int gpioNumber);
	~ButtonStop();
	void update(int value);
};

