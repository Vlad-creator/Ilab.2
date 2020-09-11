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
		int max;
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
};

void cash::look_up(int request)
{
	node_t put;
	if (cash_table.find(request) != cash_table.end())
	{
		(cash_table[request] -> year)++;
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
};

int main()
{
	cash LFU(50);
	for (int i = 0 ; i < 500 ; i++)
		LFU.look_up(i);
	for (int i = 1 ; i < 10 ; i++)
		LFU.look_up(i);
	LFU.look_up(11);
	LFU.print_cash();
	return 0;
};
	