#include "workshops.h"
#include <iostream>
//#include <strstream>
//#include <istream>
//#include <mmstream.h>
//#include <ostream>
//#include <sstream>
//#import <stream>

using namespace std;

workshops::workshops(int num)
{
	if (num) 
	{
		int type_temp;
		cout << "enter whorkshop name up to 128 characters: " << endl;
		cin.getline(m_name, 128);
		cin >> m_duration;
		cout << "enter workshop type\n1. Lecture\n2. Craft" << endl;
		do {
			cin >> type_temp;
			switch (type_temp)
			{
			case 1:
				m_type = lecture;
				break;
			case 2:
				m_type = craft;
				break;
			default:
				cout << "error! try again." << endl;
				type_temp = 0;
				break;
			}
		} while (!type_temp);
		if (m_type) {
			m_price = 45;
		}
		else {
			m_price = 39;
		}
		m_sum_times = 0;
	}
}

void workshops::add_workshop_time()
{
	if (m_sum_times >= SUM_TIMES) {
		cout << "error! there are already " << SUM_TIMES << " times" << endl;
		return;
	}m_times[m_sum_times].set_time();
}

int workshops::sell_ticket()
{
	if (m_sum_times == 0) {
		cout << "there are no times for this workshop." << endl;
		return 0;
	}
	int choice, x, y;
	cout << "choice time:\n" << endl;
	for (int i = 0; i < m_sum_times; i++) {
		cout << i + 1 << ". ";
		m_times[i].print_time();
		cout << endl;
		cin >> choice;
	}while (choice<1 || choice>m_sum_times) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}
	m_rooms[choice].print_status();
	cout << "choice seat from empty seats:" << endl;
	do {
		cout << "row: ";
		cin >> x;
		cout << "seat number: ";
		cin >> y;
	} while (x > 10 || x < 1 || y>10 || y < 1 || m_rooms[choice].return_status(x, y));
	m_rooms[choice].reserve_seat(x, y);
	return m_price;
}

int workshops::cancel_ticket_reservation()
{
	if (m_sum_times == 0) {
		cout << "there are no times for this workshop." << endl;
		return 0;
	}
	int choice, x, y;
	cout << "choice time:\n" << endl;
	for (int i = 0; i < m_sum_times; i++) {
		cout << i + 1 << ". ";
		m_times[i].print_time();
		cout << endl;
		cin >> choice;
	}while (choice<1 || choice>m_sum_times) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}
	m_rooms[choice].print_status();
	cout << "choice seat from reserve seats:" << endl;
	do {
		cout << "row: ";
		cin >> x;
		cout << "seat number: ";
		cin >> y;
	} while (x > 10 || x < 1 || y>10 || y < 1);
	if (!m_rooms[choice].return_status(x, y)) {
		return 0;
	}
	m_rooms[choice].reserve_seat(x, y);
	return m_price;
}

void workshops::print_info()
{
	cout << "name: " << m_name << "\nduration: " << m_duration << "\ntype: "\
		<< ((m_type == lecture) ? "lecture" : "craft") << "\nprice: " << m_price << "\ntimes: ";
	for (int i = 0; i < m_sum_times; i++) {
		m_times[i].print_time();
		cout << ", ";
	}
}

void workshops::print_seats_status()
{
	if (m_sum_times == 0) {
		cout << "there are no times for this workshop." << endl;
		return;
	}
	int choice;
	cout << "choice time:\n" << endl;
	for (int i = 0; i < m_sum_times; i++) {
		cout << i + 1 << ". ";
		m_times[i].print_time();
	}
	cout << endl;
	cin >> choice;
	while (choice<1 || choice>m_sum_times) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}
	m_rooms[choice].print_status();
}

void workshops::print_name()
{
	cout << m_name;
}
