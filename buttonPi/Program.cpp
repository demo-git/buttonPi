#include "Program.h"
#include "ButtonStop.h"
#include "ButtonLight.h"
#include "ButtonPower.h"

Program* Program::instance = nullptr;

Program::Program() {
}

void Program::start() {
    this->run();
    Gpio::clean();
}

void Program::run() {
    ButtonPower power(1);

    ButtonStop stop(2);
    stop.addObserver(this);

    ButtonLight light(3);
    Led firstLed(4);
    Led secondLed(5);

    light.addLed(firstLed);
    light.addLed(secondLed);

    power.addObserver(&light);

    std::unique_lock<std::mutex> conditionalLock(this->mutex);

    while (!shouldStop) {
        this->triggerStop.wait(conditionalLock);
    }

    stop.removeObserver(this);
}

void Program::stop() {
    this->shouldStop = true;
    this->triggerStop.notify_all();
}

Program *Program::getInstance() {
    if (Program::instance == nullptr) {
        Program::instance = new Program();
    }

    return Program::instance;
}

void Program::update(int value) {
    if (value == 1) {
        this->stop();
    }
}

