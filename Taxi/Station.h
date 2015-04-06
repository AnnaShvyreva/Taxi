#pragma once
#include <string>
#include <vector>
#include "Passenger.h"
#include "Car.h"

class Route;

class Station
{
public:

	Station(std::string str);
	virtual ~Station(void);

	void AddPasseger(Passenger* passenger);
	void TakePasseger(Car* car);
	//size_t WaitingPassCounte ();
	void WritingPass();

	std::string get_name() const
	{
		return name_;
	}

private:
	std::string name_;
	std::vector<Passenger*>* waitingPassenger_;
};