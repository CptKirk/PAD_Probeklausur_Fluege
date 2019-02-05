#pragma once
#include"Flight.h"

class Flightplan
{
public:
	Flightplan();
	~Flightplan();
	void book();
	void cancel();
	void show_bookings();
	void initialize();
	void auslastung();

private:
	Flight HamLeip;
	Flight LeipHam;
	Flight HamMue;
	Flight MueHam;
};

