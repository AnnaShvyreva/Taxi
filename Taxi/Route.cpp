#define _CRT_SECURE_NO_WARNINGS
#include "Route.h"
#include "Station.h"


Route::Route(size_t n)
{
	stationsRoute_ = new std::vector<Station*>[n];
	
	for (size_t i=0; i< n; i++)
	{
		(*stationsRoute_).push_back(new Station(std::to_string((int)i)));
	}
}


Route::~Route(void)
{
	for (size_t i=0; i<(*stationsRoute_).size(); i++)
	{
		delete (*stationsRoute_)[i];
	}
	delete[] stationsRoute_;
}

void Route::AddStation(Station* state)
{
	stationsRoute_->push_back(state);
}

size_t Route::ReturnStationId(std::string name)
{
	size_t i;
	for (i=0;i<stationsRoute_->size();i++)
	{
		if ((*stationsRoute_)[i]->GetName().compare(name)==0)
			return i;
	}
	return -1;
}

size_t Route::ReturnRoudLength()
{
	return stationsRoute_ -> size();
}

Station* Route::ReturnStation(int name)
{
	return (*stationsRoute_)[name];
}