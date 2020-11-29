#include "../Main/Matrix.h"
#include <fstream>

using namespace Matrix_Ilab;

int main()
{
	std::ifstream answer("../tests_e2e/answer");
	if ((answer.is_open()))
	{
		long double ans = 0;
		long double check = 0;
		std::cin >> check;
		answer >> ans;
		if (ans != check)
			std::cout << "ERROR" << std::endl;
		else
			std::cout << "TRUE" << std::endl;
	}
	answer.close();
	return 0;
};