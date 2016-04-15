#pragma once

#include <vector>
#include "Button.h"
#include "Power.h"

class ButtonPower : public Button
{
protected:
	std::vector<Power> powers;
public:
	ButtonPower();
	~ButtonPower();
	void update(int value);
	void addObject(Power power);
};

