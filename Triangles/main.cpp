#include <vector>
#include <iostream>
#include <float.h>
#include <math.h>
#include "Triangle.h"
#include "cross_tr.h"
#include "octa_tree.h"

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

	int res = 0;

	//std::cout << is_cross(TRs[0] , TRs[1]);

	octa_tree head(TRs);
	head.make_tree(&res);

	std::cout << res << std::endl;
	return 0;
}