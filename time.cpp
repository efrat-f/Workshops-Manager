#include "time.h"
#include <iostream>

using namespace std;

void time::set_time()
{
	do {
		cout << "enter hours from 1 to 24: "<< endl;
		cin >> m_hours;
	} while (m_hours < 1 || m_hours>24);
	do {
		cout << "enter minutes from 0 to 59: ";
		cin >> m_minutes;
	} while (m_minutes < 0 || m_minutes>59);
}

void time::print_time()
{
	cout << m_hours << ":" << m_minutes << endl;
}
