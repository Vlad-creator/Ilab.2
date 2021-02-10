#include <vector>
#include <set>
#include <iostream>
#include <float.h>
#include <math.h>
#include "Triangle.h"
#include "cross_tr.h"
#include "octo_tree.h"

int main()
{
	int N = 0;
	triangle per;
	std::cin >> N;
	std::vector<triangle> TRs;
	for (int i = 0 ; i < N ; ++i)
	{
		std::cin >> per;
		TRs.push_back(per);
	}

	/*octo_tree test(TRs);
	test.set_edge(10);
	std::vector<region> for_test = test.make_regions();
	for (auto it = for_test.begin() ; it != for_test.end() ; ++it)
	{
		std::cout << "zone - " << counter << std::endl;
		test.sort_triangles(*it);
		counter++;
	}*/
	//int res = 0;

	/*for (auto it_1 = TRs.begin() ; it_1 != TRs.end() ; ++it_1)
		for (auto it_2 = TRs.begin() ; it_2 != TRs.end() ; ++it_2)
			if ((it_1 != it_2) && (is_cross((*it_1) , (*it_2))))
			{
				(res)++;
				std::cout << "triangle - ";
				(*it_2).print();
				std::cout << "triangle - ";
				(*it_1).print();	
			}

	std::cout << res << std::endl;*/

	octo_tree head(TRs);
	head.set_edge();
	head.make_tree();

	//head.print();

	//std::cout << res << std::endl;
	return 0;
}