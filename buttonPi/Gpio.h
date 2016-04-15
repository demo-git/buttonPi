#pragma once

#include <string>
#include <fstream>
#include <map>
#include "Observable.h"
#include <thread>

class Gpio : public Observable
{
protected:
	static std::map<int, Gpio> gpios;
	
	const std::string EXPORT_PATH = "/sys/class/gpio/export";
	const std::string UNEXPORT_PATH = "/sys/class/gpio/unexport";

	std::thread listeningThread;
	std::string directionPath;
	std::string valuePath;
	int gpioNum;

	Gpio(int gpioNum);

	void startThread();
public:
	static Gpio getInstance(int gpioNumber);
	
	~Gpio();

	void setDirection(bool isIn);
	void setValue(int value);
	int getValue();
};

