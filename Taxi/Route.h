#pragma once
//#include <string>
#include <vector>

class Station;

class Route
{
public:
	Route(size_t n);
	virtual ~Route(void);
	void AddStation(Station* station);
	size_t ReturnStationId(std::string name);
	size_t ReturnRoudLength ();
	Station* ReturnStation(int name);

private:
	std:: string name_;
	std:: vector<Station*>* stationsRoute_;
};