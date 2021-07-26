#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Matrix.h"

int main()
{
	int N = 0;
	std::cin >> N;
	bfr::matrix<int> test{N , N};

	std::cin >> test;
	try
	{
		std::cout << test.determinant() << std::endl;
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}