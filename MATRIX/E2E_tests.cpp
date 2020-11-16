#include "Matrix.h"
#include <fstream>

using namespace Matrix_Ilab;

int main()
{
	std::ifstream tests("e2e_tests");
	std::ifstream answers("e2e_tests_answers");
	std::ofstream answers_may("results_e2e");
	if ((tests.is_open()) && (answers_may.is_open()) && (answers.is_open()))
	{
		for (int k = 0 ; k < 8 ; ++k)
		{
			int size = 0;
			tests >> size;
			matrix<int> test(size);
			for (int i = 0 ; i < test.count_str() ; ++i)
			{
				for (int j = 0 ; j < test.count_col() ; ++j)
				{
					int per = 0;
					tests >> per;
					test.put_M(i , j , per);
				}
			}
			int det = test.determinate();
			int det_res = 0;
			answers >> det_res;
			if (det_res != det)
			{
				std::cout << "Произошёл провал на матрице " << k << std::endl;
				test.print_M();
				std::cout << "Правильный ответ - " << det_res << std::endl << "А получили ответ - " << det << std::endl;
				break;
			};
			answers_may << det << std::endl;
		}
		tests.close();
		answers_may.close();
		answers.close();
	};
	return 0;
};