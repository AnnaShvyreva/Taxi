#pragma once

#include "Route.h"
#include <set>

class Passenger;

enum Direction {DOWN, UP};

class Car
{
public:

	Car(Route* route, size_t num);
	virtual ~Car(void);

	//void set_route(size_t n);
	void add_inCar(Passenger* passenger);
	void delete_inCar(int station);
	int Available_Seat();
	//int inCarIndex(Passenger* passenger);
	bool Going_Away(int station);
	
	Route& get_route();
	int get_count_plase() const;
	Direction get_direction() const;
	int get_now_station() const;
	size_t get_step() const;
	void set_direction(Direction direction);
	void set_now_station(int now_station);
	size_t get_routeNum() const;
	size_t get_step();	
	void set_route(Route* route);

protected:
	Route *myRoute_;
	size_t routeNum_;
	int countPlase_;
	//std:: vector <Passenger*>* inCar_;
	std:: vector <std::set<Passenger*>*>* inCar_;
	//std::set<Passenger*> inCar_[];
	size_t step_;
	Direction direction_;
	int nowStation_;
};