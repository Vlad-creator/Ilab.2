#include <iostream>
#include "cash.h"

int main()
{
	int sizeof_cash = 0 , count_req = 0;
	type request = 0;
	std:: cin >> sizeof_cash >> count_req; 
	std:: cout << '\n';
	cash<> LFU(sizeof_cash);
	for (int i = 0 ; i < count_req ; i++)
	{
		std:: cin >> request;
		LFU.look_up(request);
	};
	LFU.print_cash();
	return 0;
}

