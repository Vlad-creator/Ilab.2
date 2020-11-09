#include "Matrix.h"

using namespace Matrix_Ilab;

int main()
{
	int size = 0;
	std::cin >> size;
	matrix<long double> test(size);
	test.fill_M();
	long double det = test.determinate();
	std::cout << det;
	return 0;
}