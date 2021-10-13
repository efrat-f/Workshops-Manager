#include <iostream>
#include "seat.h"



seat::seat()
{
	m_status = 0;
}

void seat::reserve_seat()
{
	m_status = 1;
}

void seat::cancel_seat_reservation()
{
	m_status = 0;
}

bool seat::return_status()
{
	return m_status;
}
