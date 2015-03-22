#include "Car.h"
//#include "stdio.h"
#include "Passenger.h"
#include "stdlib.h"
#include <algorithm>


Car::Car(void)
{
	nowStation = 0;
	inCar_ = new std:: vector<Passenger*>;
}

Car::~Car(void)
{
	for (size_t i=0; i<(*inCar_).size(); i++)
	{
		delete (*inCar_)[i];
	}
	delete[] inCar_;
}

void Car::set_route(size_t n)
{
	myRoute_ = new Route(n);
}

void Car::add_inCar(Passenger* passenger)
{
	(*inCar_).push_back(passenger);
}

void Car::delete_inCar(int station)
{
	for (size_t i=0; i<(*inCar_).size();i++)
	{
		if (inCar_ -> at(i) ->ReturnDestination()==station) 
		{
			//(*inCar_).erase(std::search<std::vector<Passenger*>*, Passenger*>(inCar_, passenger));
			(*inCar_).erase((*inCar_).begin() + inCarIndex((*inCar_)[i]));
			i--;
		}
		//delete (*inCar_)[i];
	}
}

int Car::Available_Seat()
{
	return countPlase_ - (*inCar_).size();
}

int Car::inCarIndex(Passenger* passenger)
{
	for (size_t i=0; i< (*inCar_).size();i++)
		if ((*inCar_)[i] == passenger) return i;
	return -1;
}

bool Car::Going_Away(int station)
{
	for (size_t i = 0; i< (*inCar_).size();i++)
		if ((*inCar_)[i] ->ReturnDestination()==station) return true; 
	return false;
}