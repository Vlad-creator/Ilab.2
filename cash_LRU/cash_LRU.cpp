#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

struct node_t
{
	int request;
	int year;
	int hash_key;
};

class cash
{
		std::list<node_t> cash_list;
		std::unordered_map<int , std::list<node_t>::iterator> cash_table;
		int p;
		int counter;
	public:
		cash(int MAX);
		void look_up(int request);
};

cash::cash(int MAX)
{
	std::list<node_t> cash_list;
	std::unordered_map<int , std::list<node_t>::iterator> cash_table;
	p = MAX;
	counter = 0;
};

void cash::look_up(int request)
{
	node_t A;
	A.request = request;
	A.year = 1;
	A.hash_key = counter;
	counter++;
	cash_list.push_front(A);
	std::list<node_t>::iterator it = cash_list.begin();
	cash_table[counter] = it;
	for(node_t n : cash_list)
		std::cout << n.request << '\n';
};

int main()
{
	cash LFU(10);
	for (int i = 0 ; i < 10 ; i++)
		LFU.look_up(i);
	/*std::list<node_t> first_list;
	node_t A[10];
	for (int i = 0 ; i < 10 ; i++)
	{
		A[i].request = i;
		A[i].year = i;
	};
	for (int i = 0 ; i < 10 ; i++)
		first_list.push_back(A[i]);
	for (node_t n : first_list) 
        std::cout << n.year << '\n';
	std::cout << '\n';
	A[1].year = 1000;
	A[2].year = 2000;
	A[3].year = 3000;
	first_list.push_back(A[1]);
	first_list.push_front(A[2]);
	std::list<node_t>::iterator it = first_list.begin();
	std::advance(it , 5);
	first_list.insert(it , A[3]);
	unordered_map<int , node_t> first_map;
	first_map[0] = A[3];
	for (node_t n : first_list) 
        std::cout << n.year << '\n';
	unordered_map<int , node_t> first_map;
	first_map[0] = A[3];
	std::unordered_map<int , node_t>::iterator = first_map.find(0);*/
	return 0;
};
	