#include <iostream>

class matrix
{
		int type;  //Если 0 - прямоугольная матрица , 1 - квадратная матрица
		int num_col;
		int num_str;
		int count;
		float** mrx;
	public:
		matrix(int num_str , int num_col);
		matrix(int num);
		~matrix();
		int count_col() {return num_col;};
		int count_str() {return num_str;};
		int m_type() {return type;};
		float get_val(int str , int col) {return mrx[col][str];};
		int fill_M();
		int print_M();
		void put_M(int str , int col , float val) {mrx[col][str] = val;};
		matrix transpotion ();
		//float minor(int str , int col);
		float determinate();
		//matrix reverse(matrix A);
};

matrix::matrix(int num_s , int num_c)
{
	mrx = new float* [num_s];
	for (int i = 0 ; i < num_c ; ++i)
		mrx[i] = new float [num_c];
	num_col = num_c;
	num_str = num_s;
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
};

matrix::matrix(int num)
{
	mrx = new float* [num];
	for (int i = 0 ; i < num ; ++i)
		mrx[i] = new float [num];
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
			A_trans.put_M(i , j , get_val(j , i));
	return A_trans;
}

float matrix::determinate()
{
	if (type == 0)
	{
		std::cout << "Дурак , с такой не работает";
		return 0;
	};
	matrix L(num_col);
	matrix U(num_col);

	for (int i = 0 ; i < num_col ; ++i)
	{
		U.put_M(0 , i , mrx[i][0]);
		L.put_M(i , 0 , mrx[0][i] / U.get_val(0 , 0));
		L.put_M(i , i , 1);
	};

	for (int i = 1 ; i < num_col ; ++i)
		for (int j = 1 ; j < num_col ; ++j)
		{
			if (j >= i)
			{
				int sum = 0;
				for (int k = 0 ; k < i ; ++k)
					sum += U.get_val(k , j) * L.get_val(i , k);
				U.put_M(i , j , get_val(i , j) - sum);
			}
			else
			{
				int sum = 0;
				for (int k = 0 ; k < i ; ++k)
					sum += U.get_val(k , i) * L.get_val(j , k);
				U.put_M(i , j , get_val(i , j) - sum);
			};
		};

	float det = 1;
	for (int i = 0 ; i < num_col ; ++i)
		det = det * U.get_val(i , i);

	return det;
};

int main()
{
	matrix test(4);
	int res = test.fill_M();
	//matrix test_t = test.transpotion();
	//test_t.print_M();
	float det = test.determinate();
	std::cout << det;
	return 0;
}