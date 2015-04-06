#pragma once

#include <string>

class Passenger
{
public:

	Passenger(std::string name, size_t destination);
	~Passenger(void);

	size_t get_destination() //const
	{
		return destination_;
	}
	std::string get_name() const
	{
		return passName_;
	}

private:
	std::string passName_;
	size_t destination_;
};

