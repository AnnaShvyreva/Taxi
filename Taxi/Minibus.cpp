#include "Minibus.h"


Minibus::Minibus(Route* route, size_t num) : Car(route, num)
{
	countPlase_ = 7;
	step_ = 1;
}


Minibus::~Minibus(void)
{
}
