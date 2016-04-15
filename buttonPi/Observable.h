#pragma once
#include <list>
#include "IObserver.h"


class Observable
{
protected:
	std::list<IObserver*> observers;
public:
	Observable();
	~Observable();

	void addObserver(IObserver *observer);
	void removeObserver(IObserver *observer);
	void notify(int value);
};

