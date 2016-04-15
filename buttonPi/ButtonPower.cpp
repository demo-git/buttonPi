#include "ButtonPower.h"



ButtonPower::ButtonPower()
{
}


ButtonPower::~ButtonPower()
{
}

void ButtonPower::update(int value)
{
	if (value) {
		for(Power power : this->powers)
		{
			power.on();
		}
	}
	else {
		for (Power power : this->powers)
		{
			power.off();
		}
	}
}

void ButtonPower::addObject(Power power)
{
	this->powers.push_back(power);
}
