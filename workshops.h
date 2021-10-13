#pragma once
#include <iostream>
#include "room.h"
#include "time.h"

#define SUM_TIMES 3

typedef enum {
	lecture,
	craft
}Type;

class workshops
{
	char m_name[129]; 
	int m_duration;
	Type m_type;
	int m_price;
	time m_times[SUM_TIMES];
	int m_sum_times;
	room m_rooms[SUM_TIMES];
public:
	workshops(int num = 0);
	void add_workshop_time();
	int sell_ticket();
	int cancel_ticket_reservation();
	void print_info();
	void print_seats_status();
	void print_name();
};

