#include "Matrix.h"

using namespace Matrix_Ilab;

int main()
{
	int size = 0;
	int str = 0;
	int col = 0;
	std::cin >> size;
	matrix<long double> test(size);
	test.fill_M();
	std::cin >> str;
	std::cin >> col;
	long double minor = test.minor_T(str , col);
	std::cout << minor << std::endl;
	return 0;
}