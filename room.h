#pragma once
#include <iostream>
#include "seat.h"

using namespace std;

#define SUM_ROWS 10
#define SUM_SEAT_IN_ROW 10

class room {
	seat m_array[SUM_ROWS][SUM_SEAT_IN_ROW];
public:
	void reserve_seat(int x, int y);
	void cancel_seat_reservation(int x, int y);
	bool return_status(int x, int y);
	void print_status();
};