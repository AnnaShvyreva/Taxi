#pragma once
//#include <string>
#include <vector>
class Car;
class Station;

class Route
{
public:

	Route(size_t n);
	virtual ~Route(void);

	size_t Route:: get_station_size();
	void AddStation(Station* station);
	size_t get_station_id(std::string name);
	size_t get_route_length ();
	size_t get_car_size();
	Station& get_station(int name);
	void AddCar(Car* car);
	Car& get_car(size_t numCar);

private:	
	std:: vector <Car*>* carInRoute_;
	std:: vector<Station*>* stationsRoute_;
	size_t carSize_;
	size_t stationSize_;
	std:: string name_;
	
};