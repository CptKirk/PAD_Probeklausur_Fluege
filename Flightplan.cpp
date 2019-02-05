#include "Flightplan.h"



Flightplan::Flightplan()
{
	this->HamLeip = Flight::Flight();
	this->LeipHam = Flight::Flight();
	this->HamMue = Flight::Flight();
	this->MueHam = Flight::Flight();
}


Flightplan::~Flightplan()
{
}

void Flightplan::book()
{
	string from, to;

	cout << "Wo wollen Sie starten?(Hamburg, Leipzig, Muenchen) ";
	cin >> from;
	cout << endl << "Wohin wollen Sie fliegen? ";
	cin >> to;

	if (from == "Hamburg" && to == "Leipzig")
		HamLeip.book();
	else if (from == "Leipzig" && to == "Hamburg")
		LeipHam.book();
	else if (from == "Hamburg" && to == "Muenchen")
		HamMue.book();
	else if (from == "Muenchen" && to == "Hamburg")
		MueHam.book();
}

void Flightplan::cancel()
{
	string from, to;

	cout << "Wo starten Sie?(Hamburg, Leipzig, Muenchen) ";
	cin >> from;
	cout << endl << "Wohin fliegen Sie? ";
	cin >> to;

	if (from == "Hamburg" && to == "Leipzig")
		HamLeip.cancel();
	else if (from == "Leipzig" && to == "Hamburg")
		LeipHam.cancel();
	else if (from == "Hamburg" && to == "Muenchen")
		HamMue.cancel();
	else if (from == "Muenchen" && to == "Hamburg")
		MueHam.cancel();
}

void Flightplan::show_bookings()
{
	string from, to;

	cout << "Wo starten Sie?(Hamburg, Leipzig, Muenchen) ";
	cin >> from;
	cout << endl << "Wohin fliegen Sie? ";
	cin >> to;

	if (from == "Hamburg" && to == "Leipzig")
		HamLeip.show_bookings();
	else if (from == "Leipzig" && to == "Hamburg")
		LeipHam.show_bookings();
	else if (from == "Hamburg" && to == "Muenchen")
		HamMue.show_bookings();
	else if (from == "Muenchen" && to == "Hamburg")
		MueHam.show_bookings();
}

void Flightplan::initialize()
{
	this->HamLeip.setFromDestination("Hamburg");
	this->HamLeip.setToDestination("Leipzig");

	this->LeipHam.setFromDestination("Leipzig");
	this->LeipHam.setToDestination("Hamburg");

	this->HamMue.setFromDestination("Hamburg");
	this->HamMue.setToDestination("Muenchen");

	this->MueHam.setFromDestination("Muenchen");
	this->MueHam.setToDestination("Hamburg");
}

void Flightplan::auslastung()
{
	cout << endl;
	cout << "Hamburg-Leipzig: " << HamLeip.getOccupiedSeats() << " von 132 Plaetzen besetzt." << endl;
	cout << "Leipzig-Hamburg: " << LeipHam.getOccupiedSeats() << " von 132 Plaetzen besetzt." << endl;
	cout << "Hamburg-Muenchen: " << HamMue.getOccupiedSeats() << " von 132 Plaetzen besetzt." << endl;
	cout << "Muenchen-Hamburg: " << MueHam.getOccupiedSeats() << " von 132 Plaetzen besetzt." << endl;
}
