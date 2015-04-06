#include "Bus.h"


Bus::Bus(Route* route, size_t num) : Car(route, num)
{
	countPlase_ = 13;
	step_ = 2;
}


Bus::~Bus(void)
{
}
