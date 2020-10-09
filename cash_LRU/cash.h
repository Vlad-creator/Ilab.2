#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

typedef int type;

template<typename T>
struct node_t
{
	T request;
	int year;
};

template <typename T = int>
class cash
{
		std::list<node_t<T>> cash_list;
		std::unordered_map<T , typename std::list<node_t<T>>::iterator> cash_table;
		//void swap_node(std::list<node_t>::iterator node_1 , std::list<node_t>::iterator node_2);
		//void shift_down(int request);
		int max;
		int counter;
		int tryes;
	public:
		cash(int MAX);
		void look_up(T request);
		void print_cash();
};

template<typename T>
cash<T>::cash(int MAX)
{
	std::list<node_t<T>> cash_list;
    std::unordered_map<T , typename std::list<node_t<T>>::iterator> cash_table;
	max = MAX;
	counter = 0;
	tryes = 0;
};

template<typename T>
void cash<T>::look_up(T request)
{
	tryes++;
	node_t<T> put;
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
			typename std::list<node_t<T>>::iterator it = cash_list.begin();
			cash_table[put.request] = it;
		}
		else
		{
			typename std::list<node_t<T>>::iterator min = cash_list.begin();
			typename std::list<node_t<T>>::iterator per = cash_list.begin();
			while (per != cash_list.end())
			{
				if (min -> year > per -> year)
					min = per;
				per++;
			};
			cash_table.erase(cash_table.find(min -> request));
			cash_list.erase(min);
			cash_list.push_front(put);
			typename std::list<node_t<T>>::iterator it = cash_list.begin();
			cash_table[put.request] = it;
		};
	};
};

template<typename T>
void cash<T>::print_cash()
{
	for (node_t<T> n : cash_list)
		std::cout << n.request << '-' << n.year <<'\t';
	
	std::cout << '\n';
	std:: cout  << cash_list.size() << '\t';
	std:: cout << cash_table.size() << '\n';
	std:: cout << counter << '\t' << tryes << '\n';
};