#pragma once


#include <condition_variable>
#include "IObserver.h"

class Program : public IObserver {
protected:
    static Program* instance;

    Program();

    std::condition_variable triggerStop;
    std::mutex mutex;
    bool shouldStop = false;
public:
    void start();
    void run();
    void stop();

    void update(int value);

    static Program* getInstance();
};