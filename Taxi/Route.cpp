#define _CRT_SECURE_NO_WARNINGS
#include "Route.h"
#include "Station.h"


Route::Route(size_t n)
{
	stationSize_ = n;
	stationsRoute_ = new std::vector<Station*>[stationSize_];
	
	for (size_t i=0; i< n; i++)
	{
		(*stationsRoute_).push_back(new Station(std::to_string((int)i)));
	}

	carInRoute_ = new std::vector<Car*>;
}


Route::~Route(void)
{
	for (size_t i=0; i<(*stationsRoute_).size(); i++)
	{
		//delete (*stationsRoute_)[i];
		if (!(*stationsRoute_)[i])
			delete (*stationsRoute_)[i];
		
	}
	delete[] stationsRoute_;
}

void Route::AddStation(Station* state)
{
	stationsRoute_->push_back(state);
}

void Route::AddCar(Car* car)
{
	carInRoute_->push_back(car);
}

Car& Route::get_car(size_t numCar)
{
	return *(*carInRoute_)[numCar];
}

size_t Route::get_station_id(std::string name)
{
	size_t i;
	for (i=0;i<stationsRoute_->size();i++)
	{
		if ((*stationsRoute_)[i]->get_name().compare(name)==0)
			return i;
	}
	return -1;
}

size_t Route::get_route_length()
{
	return stationsRoute_ -> size();
}

size_t Route::get_car_size()
{
	return carInRoute_ -> size();
}

size_t Route:: get_station_size()
{
	return stationSize_;
}

Station& Route::get_station(int name)
{
	return *(*stationsRoute_)[name];
}