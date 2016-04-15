#pragma once

#include <vector>
#include "Button.h"
#include "Power.h"

class ButtonPower : public Button, public Observable
{
public:
	ButtonPower();
	~ButtonPower();
	void update(int value);
};

