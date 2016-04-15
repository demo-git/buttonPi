#include "Observable.h"



Observable::Observable()
{
}


Observable::~Observable()
{
}

void Observable::addObserver(IObserver *observer)
{
	this->observers.push_back(observer);
}

void Observable::removeObserver(IObserver *observer)
{
	this->observers.remove(observer);
}

void Observable::notify(int value)
{
	for (IObserver *observer : this->observers) {
		observer->update(value);
	}
}
