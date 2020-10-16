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
		~matrix();
		int count_col() {return num_col;};
		int count_str() {return num_str;};
		int m_type() {return type;};
		int get_val(int str , int col) {return mrx[col][str];};
		int fill_M();
		int print_M();
		void put_M(int val , int str , int col) {mrx[col][str] = val;};
		matrix transpotion ();
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

matrix::~matrix()
{
	for (int i = 0 ; i < num_col ; ++i)
		delete[] mrx[i];
	delete[] mrx;
	std::cout << "deleted" << "\n";
}

int matrix::fill_M()
{
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


matrix matrix::transpotion()
{
	int num_c = count_str();
	int num_s = count_col();
	matrix A_trans(num_s , num_c);
	for (int i = 0 ; i < num_s ; i++)
		for (int j = 0 ; j < num_c ; j++)
			A_trans.put_M(get_val(j , i) , i , j);
	return A_trans;
}

int main()
{
	matrix test(2 , 3);
	int res = test.fill_M();
	matrix test_t = test.transpotion();
	test_t.print_M();
	return 0;
}