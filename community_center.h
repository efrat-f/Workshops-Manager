#pragma once
#include <iostream>
#include "workshops.h"

#define MAX_WORKSHOP 5

class community_center
{
	char m_name[129];
	char m_city[129];
	workshops m_workshops[MAX_WORKSHOP];
	int m_sum_workshops;

	static int tickets_sold;
	static int money_earned;
public:
	community_center(int num = 0);
	void add_workshop();
	void add_time();
	void print_info_workshops();
	void Print_seat_status();
	void sell_ticket();
	void cancel_ticket();
	void print_tickets_sold();
	void print_money_earned();
	void print_name();
};

