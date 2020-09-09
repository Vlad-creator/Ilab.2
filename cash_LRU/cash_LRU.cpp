#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

struct node_t
{
	int value;
	int year;
	int hash_key;
};

int main()
{
	std::list<node_t> first_list;
	node_t A[10];
	for (int i = 0 ; i < 10 ; i++)
	{
		A[i].value = i;
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
	std::list<node_t> :: iterator it = first_list.begin();
	std::advance(it , 5);
	first_list.insert(it , A[3]);
	unordered_map<int , node_t> first_map;
	first_map[0] = A[3];
	std::unordered_map<int , node_t> ::iterator = first_map.find(0);
	
	for (node_t n : first_list) 
        std::cout << n.year << '\n';
	return 0;
};
	