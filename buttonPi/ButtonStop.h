#pragma once

#include "Button.h"

class ButtonStop : public Button
{
public:
	ButtonStop(int gpioNumber);
	~ButtonStop();
	void update(int value);
};

