#include "Gpio.h"

Gpio::Gpio(int gpioNum)
{
	this->directionPath = "/sys/class/gpio/gpio" + std::to_string(gpioNum) + "/direction";
	this->valuePath = "/sys/class/gpio/gpio" + std::to_string(gpioNum) + "/value";
	this->gpioNum = gpioNum;
	std::ofstream f(this->EXPORT_PATH, std::ios::trunc);
	f << std::to_string(gpioNum);
	f.close();
}


Gpio::~Gpio()
{
	std::ofstream f(this->UNEXPORT_PATH, std::ios::trunc);
	f << std::to_string(this->gpioNum);
	f.close();
}

void Gpio::setDirection(bool isIn)
{
	std::ofstream f(this->directionPath, std::ios::trunc);
	f << (isIn ? "in" : "out");
	f.close();
}

void Gpio::setValue(int value)
{
	std::ofstream f(this->valuePath, std::ios::trunc);
	f << value;
	f.close();
}

int Gpio::getValue()
{
	int value;
	std::ifstream f(this->valuePath);
	f >> value;
	f.close();

	return value;
}
