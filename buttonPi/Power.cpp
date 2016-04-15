#include "Power.h"

Power::~Power()
{
}

void Power::on()
{
	this->state = true;
}

void Power::off()
{
	this->state = false;
}
