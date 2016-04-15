#pragma once
class Power
{
protected:
	bool state = false;
public:
	virtual ~Power();
	virtual void on();
	virtual void off();
};

