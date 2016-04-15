#pragma once

#include "Led.h"
#include <vector>
#include "IObserver.h"

class Button : public IObserver
{
public:
	virtual ~Button();
};

