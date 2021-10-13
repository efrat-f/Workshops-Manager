#pragma once
#include <iostream>

using namespace std;

class seat {
	bool m_status; //indicate if seat vacant(0) or occupied(1).
public:
	seat();
	void reserve_seat();
	void cancel_seat_reservation();
	bool return_status();
};
