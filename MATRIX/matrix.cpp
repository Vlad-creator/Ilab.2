#include <iostream>

class matrix
{
		int type;  //Если 0 - прямоугольная матрица , 1 - квадратная матрица
		int num_col;
		int num_str;
		int count;
		int** mrx;
	public:
		matrix(int num_str , int num_col);
		matrix(int num);
		int fill_M(/*FILE* in*/);
		int print_M();
		//matrix transpotion (matrix A);
		//int determinate(matrix A);
		//matrix reverse(matrix A);
};

matrix::matrix(int num_s , int num_c)
{
	mrx = new int* [num_s];
	for (int i = 0 ; i < num_c ; ++i)
		mrx[i] = new int [num_c];
	num_col = num_c;
	num_str = num_s;
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
};

matrix::matrix(int num)
{
	mrx = new int* [num];
	for (int i = 0 ; i < num ; ++i)
		mrx[i] = new int [num];
	num_col = num;
	num_str = num;
	count = num_col * num_str;
	type = 1;
};

int matrix::fill_M(/*FILE* in*/)
{
	/*int* per_mrx = new int (count);
	fread(per_mrx , sizeof(int) , count , in);
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; i < num_col ; ++i)
		{
			if ((i + j) >= count)
				return 0;
			mrx[i][j] = per_mrx[i + j];
		}*/
	for (int i = 0 ; i < num_str ; i++)
	{
		for (int j = 0 ; j < num_col ; j++)
			std::cin >> mrx[j][i];

	}
	return 1;
};

int matrix::print_M()
{
	std::cout << "count = " << count << "\n";
	std::cout << "num_col = " << num_col << "\n";
	std::cout << "num_str = " << num_str << "\n";
	std::cout << "type = " << type << "\n";
	for (int i = 0 ; i < num_str ; i++)
	{
		for (int j = 0 ; j < num_col ; j++)
			std::cout << mrx[j][i] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
	return 1;
}









int main()
{
	matrix test(2);
	int res = test.fill_M();
	printf("%d\n" , res);
	res = test.print_M();
	printf("%d\n" , res);
	return 0;
}