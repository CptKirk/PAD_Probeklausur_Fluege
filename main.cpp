#include<iostream>
#include"Flightplan.h"

int main() {
	Flightplan newPlan = Flightplan::Flightplan();
	newPlan.initialize();

	int input = 0;

	while (true) {
		cout << "1:  Platz buchen" << endl
			<< "2:  Platz stornieren" << endl
			<< "3:  Belegung anzeigen" << endl
			<< "4:  Auslastungsuebersicht" << endl
			<< "0:  Programm beenden" << endl;

		cin >> input;

		switch (input)
		{
		case(1): newPlan.book(); break;
		case(2): newPlan.cancel(); break;
		case(3): newPlan.show_bookings(); break;
		case(4): newPlan.auslastung(); break;
		case(0): exit(0); break;
		default: exit(0); break;
		}

		cout << endl << endl << endl;
	}
}