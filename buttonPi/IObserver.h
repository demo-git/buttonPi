#pragma once
class IObserver
{
public:
	virtual ~IObserver();
	virtual void update(int value) = 0;
};

