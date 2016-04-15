#pragma once

#include <string>
#include <fstream>

class Gpio
{
protected:
	const std::string EXPORT_PATH = "/sys/class/gpio/export";
	const std::string UNEXPORT_PATH = "/sys/class/gpio/unexport";
	std::string directionPath;
	std::string valuePath;
	int gpioNum;
public:
	Gpio(int gpioNum);
	~Gpio();
	void setDirection(bool isIn);
	void setValue(int value);
	int getValue();
};

