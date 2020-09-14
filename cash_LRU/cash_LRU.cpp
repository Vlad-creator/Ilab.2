#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

struct node_t
{
	int request;
	int year;
};

class cash
{
		std::list<node_t> cash_list;
		std::unordered_map<int , std::list<node_t>::iterator> cash_table;
		//void swap_node(std::list<node_t>::iterator node_1 , std::list<node_t>::iterator node_2);
		//void shift_down(int request);
		int max;
		int counter;
		int tryes;
	public:
		cash(int MAX);
		void look_up(int request);
		void print_cash();
};

cash::cash(int MAX)
{
	std::list<node_t> cash_list;
	std::unordered_map<int , std::list<node_t>::iterator> cash_table;
	max = MAX;
	counter = 0;
	tryes = 0;
};

void cash::look_up(int request)
{
	tryes++;
	node_t put;
	if (cash_table.find(request) != cash_table.end())
	{
		(cash_table[request] -> year)++;
		counter++;
	}
	else
	{
		put.request = request;
		put.year = 1;
		if (cash_list.size() != max)
		{
			cash_list.push_front(put);
			std::list<node_t>::iterator it = cash_list.begin();
			cash_table[put.request] = it;
		}
		else
		{
			std::list<node_t>::iterator min = cash_list.begin();
			std::list<node_t>::iterator per = cash_list.begin();
			while (per != cash_list.end())
			{
				if (min -> year > per -> year)
					min = per;
				per++;
			};
			cash_table.erase(cash_table.find(min -> request));
			cash_list.erase(min);
			cash_list.push_front(put);
			std::list<node_t>::iterator it = cash_list.begin();
			cash_table[put.request] = it;
		};
	};
};
	
void cash::print_cash()
{
	for (node_t n : cash_list)
		std::cout << n.request << '-' << n.year <<'\t';
	std::cout << '\n';
	std:: cout  << cash_list.size() << '\t';
	std:: cout << cash_table.size() << '\n';
	std:: cout << counter << '\t' << tryes << '\n';
};

int main()
{
	int sizeof_cash = 0 , count_req = 0 , request = 0;
	std:: cin >> sizeof_cash >> count_req; 
	std:: cout << '\n';
	cash cash_LFU(sizeof_cash);
	for (int i = 0 ; i < count_req ; i++)
	{
		std:: cin >> request;
		std:: cout << '\n';
		cash_LFU.look_up(request);
	};
	cash_LFU.print_cash();
	return 0;
};
	