#include "Gpio.h"
#include <fcntl.h>
#include <unistd.h>

Gpio::Gpio(int gpioNum, bool shouldListen)
{
	this->directionPath = "/sys/class/gpio/gpio" + std::to_string(gpioNum) + "/direction";
	this->valuePath = "/sys/class/gpio/gpio" + std::to_string(gpioNum) + "/value";
	this->gpioNum = gpioNum;

	std::ofstream f(this->EXPORT_PATH, std::ios::trunc);
	f << gpioNum;
	f.close();

	this->setDirection(shouldListen);
	this->listening = shouldListen;
	if (shouldListen) {
		this->listeningThread = std::thread(&Gpio::startThread, this);
	}
}

void Gpio::startThread()
{
	int fd;
	fd_set fds;
	char buffer[1];
	char oldBuffer[1];


	if ((fd = open(this->valuePath.c_str(), O_RDONLY)) < 0) {
		perror("Could not open " + this->valuePath);
		exit(EXIT_FAILURE);
	}

	read(fd, &oldBuffer, 1);

	while (!this->shouldStop) {
		FD_ZERO(& fds);
		FD_SET(fd, & fds);

		if (select(fd+1, NULL, NULL, & fds, NULL) > 0) {
			if (read(fd, & buffer, 1) != 1) {
				perror("Trouble reading the new value");
			} else {
				this->notify(buffer[0] == '1' ? 1 : 0);
			}
		}
	}

	close(fd);
}

void Gpio::startThread2()
{
	int oldValue = this->getValue();
	int value;

	while (!this->shouldStop) {
		usleep(50);
		value = this->getValue();

		if (value != oldValue) {
			oldValue = value;
			this->notify(value);
		}
	}
}

Gpio::~Gpio()
{
	//TODO : pas sur que ça réveille le select
	this->shouldStop = true;
	std::ofstream f(this->UNEXPORT_PATH, std::ios::trunc);
	f << this->gpioNum;
	f.close();

	if (this->listening) {
		this->listeningThread.join();
	}
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

Gpio* Gpio::getInstance(int gpioNumber, bool shouldListen)
{
	if (Gpio::gpios.count(gpioNumber) == 0) {
		Gpio gpio(gpioNumber, shouldListen);
		Gpio::gpios.insert(std::map<int, Gpio>::value_type(gpioNumber, gpio));
	}

	return &Gpio::gpios.at(gpioNumber);
}
