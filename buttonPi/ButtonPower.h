#pragma once

#include <vector>
#include "Button.h"
#include "Power.h"

class ButtonPower : public Button
{
public:
	ButtonPower();
	~ButtonPower();
	void update(int value);
};

