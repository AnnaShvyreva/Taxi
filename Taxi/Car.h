#pragma once

#include "Route.h"

class Passenger;

enum Direction {DOWN, UP};

class Car
{
public:
	Direction direction;
	size_t nowStation;

	Car(void);
	virtual ~Car(void);

	void set_route(size_t n);
	void add_inCar(Passenger* passenger);
	void delete_inCar(int station);
	int Available_Seat();
	int inCarIndex(Passenger* passenger);
	bool Going_Away(int station);

	Route* get_route() const
	{
		return myRoute_;
	}

	int count_plase() const
	{
		return countPlase_;
	}

protected:
	Route *myRoute_;
	int countPlase_;
	std:: vector <Passenger*>* inCar_;
};