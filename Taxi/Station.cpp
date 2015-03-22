#include "Station.h"
#include "Route.h"
#include <iostream>

Station::Station(std::string stname)
{
	name_ = stname;
	waitingPassenger_ = new std::vector<Passenger*>;
}

Station::~Station(void)
{
	for (size_t i=0; i<(*waitingPassenger_).size(); i++)
	{
		delete (*waitingPassenger_)[i];
	}
	delete[] waitingPassenger_;
}

void Station::AddPasseger(Passenger* passenger)
{
	waitingPassenger_->push_back(passenger);
}

void Station::TakePasseger(Car* car) //проверка, какого пассажира брать, если он есть
{
	for (int i = 0; i<waitingPassenger_->size();i++)
	{
		int currentDestination = waitingPassenger_->at(i)->ReturnDestination();
		int st = car->nowStation -1;
		int result = currentDestination - st;
		if (((currentDestination - st <0) && car->direction==UP) || 
			((currentDestination - st >0) && car->direction==DOWN))
		{
			if (car->Available_Seat())
			{
				car ->add_inCar((*waitingPassenger_)[i]);
				(*waitingPassenger_).erase((*waitingPassenger_).begin() + i);
				i--;
			}
		}		
	}
}

void Station::WritingPass()
{
	for (size_t i=0; i< (*waitingPassenger_).size(); i++)
	{
		std:: cout << (*waitingPassenger_)[i] ->Get_Name() << "(";
		std:: cout << (*waitingPassenger_)[i] ->ReturnDestination()+1 << ") ";
	}
}

//size_t Station::WaitingPassCounte()
//{
//	return (*waitingPassenger_).size();
//}