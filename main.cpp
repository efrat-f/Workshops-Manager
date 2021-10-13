#include <iostream>
#include "seat.h"
#include "time.h"
#include "room.h"
#include "workshops.h"
//#include "func.h"
#include "community_center.h"

using namespace std;

int main()
{
	community_center m_array(1);
	//len_array = 0;
	int choice;
	cout << "welcome to a Workshop Manager!\nmenu:\n\
1. Add a community center\n\
2. Add a workshop for community center\n\
3. Print the information of available workshops of community center\n\
4. Print the seat status of a certain show on a certain workshop time of community center.\n\
5. Sell ticket to a workshop of community center.\n\
6. Cancel ticket to a workshop of community center.\n\
7. Print the amount of tickets sold so far of community center.\n\
8. Print the amount of money earned in total of community center\n\
9. for exit." << endl;
	do {
		cout << "your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			/*community_center temp_center(1);
			m_array[len_array] = temp_center;
			len_array++;*/
			m_array.add_time();
			break;
		case 2:
			m_array.add_workshop();
			break;
		case 3:
			m_array.print_info_workshops();
			break;
		case 4:
			m_array.Print_seat_status();
			break;
		case 5:
			m_array.sell_ticket();
			break;
		case 6:
			m_array.cancel_ticket();
			break;
		case 7:
			m_array.print_tickets_sold();
			break;
		case 8:
			m_array.print_money_earned();
			break;
		case 9:
			cout << "good bye!" << endl;
			break;
		default:
			cout << "ilegal!" << endl;
			break;
		}
	} while (choice != 9);
}