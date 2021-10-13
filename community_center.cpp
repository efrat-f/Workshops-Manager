#include "community_center.h"

using namespace std;

int community_center::tickets_sold = 0;
int community_center::money_earned = 0;

community_center::community_center(int num)
{
	if (num)
	{
		cout << " Community Center name up to 128 characters: " << endl;
		cin.getline(m_name, 128);
		cout << "enter city name up to 128 characters: " << endl;
		cin.getline(m_city, 128);
		m_sum_workshops = 0;
	}
}

void community_center::add_workshop()
{
	if (m_sum_workshops == MAX_WORKSHOP) {
		cout << "error! there are already " << MAX_WORKSHOP << " workshop in this Community Center " << endl;
		return;
	}
	workshops temp_workshops(1);
	m_workshops[m_sum_workshops] = temp_workshops;
	m_sum_workshops++;
}

void community_center::add_time()
{
	if (m_sum_workshops == 0) {
		cout << "there are no workshops for this Community Center ." << endl;
		return;
	}
	int choice;
	cout << "choice workshop:\n" << endl;
	for (int i = 0; i < m_sum_workshops; i++) {
		cout << i + 1 << ". ";
		m_workshops[i].print_name();
	}
	cout << endl;
	cin >> choice;
	while (choice<1 || choice>m_sum_workshops) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}m_workshops[choice].add_workshop_time();
}

void community_center::print_info_workshops()
{
	cout << "information of available workshops:" << endl;
	for (int i = 0; i < m_sum_workshops; i++) {
		m_workshops[i].print_info();
	}
}

void community_center::Print_seat_status()
{
	if (m_sum_workshops == 0) {
		cout << "there are no workshops for this Community Center ." << endl;
		return;
	}
	int choice;
	cout << "choice workshop:\n" << endl;
	for (int i = 0; i < m_sum_workshops; i++) {
		cout << i + 1 << ". ";
		m_workshops[i].print_name();
	}
	cout << endl;
	cin >> choice;
	while (choice<1 || choice>m_sum_workshops) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}
	m_workshops[choice].print_seats_status();
}

void community_center::sell_ticket()
{
	if (m_sum_workshops == 0) {
		cout << "there are no workshops for this Community Center ." << endl;
		return;
	}
	int choice;
	cout << "choice workshop:\n" << endl;
	for (int i = 0; i < m_sum_workshops; i++) {
		cout << i + 1 << ". ";
		m_workshops[i].print_name();
	}
	cout << endl;
	cin >> choice;
	while (choice<1 || choice>m_sum_workshops) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}int temp = m_workshops[choice].sell_ticket();
	if (temp) {
		community_center::money_earned += temp;
		community_center::tickets_sold += 1;
	}
}

void community_center::cancel_ticket()
{
	if (m_sum_workshops == 0) {
		cout << "there are no workshops for this Community Center ." << endl;
		return;
	}
	int choice;
	cout << "choice workshop:\n" << endl;
	for (int i = 0; i < m_sum_workshops; i++) {
		cout << i + 1 << ". ";
		m_workshops[i].print_name();
	}
	cout << endl;
	cin >> choice;
	while (choice<1 || choice>m_sum_workshops) {
		cout << "ilegal! try again" << endl;
		cin >> choice;
	}int temp = m_workshops[choice].cancel_ticket_reservation();
	if (temp) {
		community_center::money_earned -= temp;
		community_center::tickets_sold -= 1;
	}
}

void community_center::print_tickets_sold()
{
	cout << " amount of tickets sold: " << community_center::tickets_sold << endl;
}

void community_center::print_money_earned()
{
	cout << "amount of money earned: " << community_center::money_earned << endl;
}

void community_center::print_name()
{
	cout << m_name;
}
