#pragma once
#include<string>
#include<iostream>
using namespace std;

class Flight
{
public:
	Flight();
	~Flight();
	void book();
	void cancel();
	void show_bookings();
	void setFromDestination(string dest);
	void setToDestination(string dest);
	int getOccupiedSeats();

private:
	int occupiedSeats = 0;
	string seats[22][6];
	string fromDestination;
	string toDestination;
};

