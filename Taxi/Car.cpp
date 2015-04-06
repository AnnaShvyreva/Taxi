#include "Car.h"
//#include "stdio.h"
#include "Passenger.h"
#include "stdlib.h"
#include <algorithm>


Car::Car(Route* route, size_t num)
{
	nowStation_ = 1;
	set_route(route);
	routeNum_ = num;
	inCar_ = new std:: vector<std::set<Passenger*>*>(num);
	for (size_t i=0; i<num; i++)
		(*inCar_)[i] = new std::set<Passenger*>;
	direction_ = DOWN;
	//set_now_station(0);
	//set_direction(DOWN);
	//inCar_ = new std:: vector<Passenger*>;
	//inCar_ = new std::vector <std::set<Passenger*>*>;
}

Car::~Car(void)
{
	for (size_t i=0; i<(*inCar_).size(); i++)
	{
		delete (*inCar_)[i];
	}
	delete[] inCar_;
}

//void Car::set_route(size_t n)
//{
//	myRoute_ = new Route(n);
//	inCar_ = new std:: vector<std::set<Passenger*>*>(n);
//	for (size_t i=0; i<n; i++)
//		(*inCar_)[i] = new std::set<Passenger*>;
//}

void Car::set_route(Route* route)
{
	myRoute_ = route;
}

void Car::add_inCar(Passenger* passenger)
{
	//(*inCar_).push_back(passenger);
	((*inCar_)[(*passenger).get_destination()]) -> insert(passenger);
}

void Car::delete_inCar(int station)
{

	(*inCar_)[station] -> erase( (*inCar_)[station] -> begin(), (*inCar_)[station] -> end());

//	for (size_t i=0; i<(*inCar_).size();i++)
//	{
//		if (inCar_ -> at(i) ->get_destination()==station) 
//		{
//			//(*inCar_).erase(std::search<std::vector<Passenger*>*, Passenger*>(inCar_, passenger));
//			(*inCar_).erase((*inCar_).begin() + inCarIndex((*inCar_)[i]));
//			i--;
//		}
//	}
}

int Car::Available_Seat()
{
	int count=0;
	for (size_t i=0; i<(*inCar_).size(); i++)
	{
		count += (*inCar_)[i] -> size();
	}
	return countPlase_ - count;
}

//int Car::inCarIndex(Passenger* passenger)
//{
//	for (size_t i=0; i< (*inCar_).size();i++)
//		if ((*inCar_)[i] == passenger) return i;
//	return -1;
//}

bool Car::Going_Away(int station)
{

	if ((*inCar_)[station] ->empty())
		return false;
	else
		return true;

//	for (size_t i = 0; i< (*inCar_).size();i++)
//		if ((*inCar_)[i] ->get_destination()==station) return true; 
//	return false;
}

Route& Car::get_route()
{
	return *myRoute_;
}

int Car::get_count_plase() const
{
	return countPlase_;
}

Direction Car::get_direction() const
{
	return direction_;
}

int Car::get_now_station() const
{
	return nowStation_;
}

size_t Car::get_step() const
{
	return step_;
}

size_t Car::get_routeNum() const
{
	return routeNum_;
}

size_t Car::get_step()
{
	return step_;
}

void Car::set_direction(Direction direction)
{
	direction_ = direction;
}

void Car::set_now_station(int now_station)
{
	nowStation_ = now_station;
}