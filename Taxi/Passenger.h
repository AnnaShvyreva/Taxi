#pragma once

#include <string>

class Passenger
{
public:
	Passenger(std::string name, size_t destination);
	~Passenger(void);

	size_t ReturnDestination() //const
	{
		return destination_;
	}

	std::string Get_Name() const
	{
		return passName_;
	}

private:
	std::string passName_;
	size_t destination_;
};

