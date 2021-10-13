#include <iostream>
#include "room.h"


void room::reserve_seat(int x, int y)
{
	m_array[x-1][y-1].reserve_seat();
	cout << "seat:" << x  << ", " << y << "is reserve." << endl;
}

void room::cancel_seat_reservation(int x, int y)
{
	if (m_array[x-1][y-1].return_status())
	{
		m_array[x-1][y-1].cancel_seat_reservation();
		cout << "reserve of seat:" << x << ", " << y << "is cancel." << endl;
	}
	else {
		cout << "error: seat:" << x << ", " << y << "is not reserve." << endl;
	}
}

bool room::return_status(int x, int y)
{
	return m_array[x-1][y-1].return_status();
}

void room::print_status()
{
	for (int i = 0; i < SUM_ROWS; i++) {
		for (int j = 0; j < SUM_SEAT_IN_ROW; j++) {
			if (m_array[i][j].return_status()) {
				cout << "*";
			}
			else {
				cout << "_";
			}
		}cout << endl;
	}
}
