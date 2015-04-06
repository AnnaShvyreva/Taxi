#pragma once

#include "car.h"
#include "Route.h"

class Minibus : public Car
{
public:

	Minibus(Route* route, size_t num);
	virtual ~Minibus(void);

};

