#include "Flight.h"



Flight::Flight()
{
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 6; j++) {
			seats[i][j] = "frei";
		}
	}
}


Flight::~Flight()
{
}

void Flight::book()
{
	int count = 0;
	int row;
	string seat;
	string name, surname;
	char gangFenster;

	cout << "Wie heißen Sie mit Vornamen? ";
	cin >> name;
	cout << endl << "Wie heißen Sie mit Nachnamen? ";
	cin >> surname;
	cout << endl << "Wollen sie lieber am Gang (G) oder am Fenster (F) sitzen? ";
	cin >> gangFenster;
	cout << endl << endl;

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 6; j++) {
			if (seats[i][j] == "frei" &&
				count == 0 &&
				gangFenster == 'F' &&
				(char(j) + 'a' == 'a' || 
				char(j) + 'a' == 'f')) {

				seats[i][j] = name + ", " + surname;
				row = i + 1;
				seat = char(j) + 'a';
				count++;
			}

			else if (seats[i][j] == "frei" &&
				count == 0 &&
				gangFenster == 'G' &&
				(char(j) + 'a' == 'c' ||
				char(j) + 'a' == 'd')) {

				seats[i][j] = name + ", " + surname;
				row = i + 1;
				seat = char(j) + 'a';
				count++;
			}
		}
	}

	if (count == 0) {
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 6; j++) {
				if (seats[i][j] == "frei" && count == 0) {

					seats[i][j] = name + ", " + surname;
					row = i + 1;
					seat = char(j) + 'a';
					count += 2;
				}
			}
		}
	}

	if (count == 1) {
		cout << "Wir haben Platz " << row << seat << " fuer Sie reserviert.";
		occupiedSeats++;
	}
	else if (count == 0)
		cout << "Der Flug ist leider ausgebucht";
	else if (count == 2 && gangFenster == 'F') {
		cout << "Wir haben Platz " << row << seat << " fuer Sie reserviert, " <<
			"da kein Platz am Fenster mehr frei war";
		occupiedSeats++;
	}
	else if (count == 2 && gangFenster == 'G') {
		cout << "Wir haben Platz " << row << seat << " fuer Sie reserviert, " <<
			"da kein Platz am Gang mehr frei war";
		occupiedSeats++;
	}
}

void Flight::cancel()
{
	int row;
	char seat;

	cout << "Bitte geben Sie ihre Reihe an: ";
	cin >> row;
	cout << endl << "Bitte geben Sie ihren Platz an: ";
	cin >> seat;

	if (seats[row - 1][seat - 'a'] != "frei") {
		seats[row - 1][seat - 'a'] = "frei";
		occupiedSeats--;
	}
	else
		cout << endl << "Der Platz ist noch nicht belegt.";
}

void Flight::show_bookings()
{
	for (int i = 0; i < 22; i++) {
		cout << endl << (i + 1) << ":   ";
		for (int j = 0; j < 6; j++) {
			cout << seats[i][j] << "   ";
		}
	}
}

void Flight::setFromDestination(string dest)
{
	this->fromDestination = dest;
}

void Flight::setToDestination(string dest)
{
	this->toDestination = dest;
}

int Flight::getOccupiedSeats()
{
	return this->occupiedSeats;
}
