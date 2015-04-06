#pragma once

#include "car.h"

class Bus : public Car
{
public:

	Bus(Route* route, size_t num);
	~Bus(void);

};

