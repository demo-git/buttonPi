#pragma once

#include <string>
#include <fstream>
#include <map>
#include "Observable.h"
#include <thread>
#include <atomic>

class Gpio : public Observable
{
protected:
	static std::map<int, Gpio*> gpios;
	
	const std::string EXPORT_PATH = "/sys/class/gpio/export";
	const std::string UNEXPORT_PATH = "/sys/class/gpio/unexport";

	std::thread listeningThread;
	std::string directionPath;
	std::string valuePath;

	std::atomic<bool> shouldStop;

	bool listening;
	int gpioNum;

	Gpio(int gpioNum, bool shouldListen);

	void startThread();
	void startThread2();
public:
	static Gpio* getInstance(int gpioNumber, bool shouldListen);

	~Gpio();
	static void clean();

	void setDirection(bool isIn);
	void setValue(int value);
	int getValue();
};

