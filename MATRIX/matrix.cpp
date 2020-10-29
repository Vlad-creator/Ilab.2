#include <iostream>
#include <iomanip>
#include <assert.h>

template<typename T>
class matrix
{
		int type;  //Если 0 - прямоугольная матрица , 1 - квадратная матрица
		int num_col;
		int num_str;
		int count;
		T** mrx;
	public:
		matrix<T>(int num_str , int num_col);
		matrix<T>(int num);
		matrix(const matrix& rhs);
		matrix<T>& operator=(const matrix& rhs);
		matrix<T>& operator+(const matrix& rhs);
		matrix<T>& operator-(const matrix& rhs);
		matrix<T>& operator*(const matrix& rhs);
		matrix<T> operator[](const matrix& rhs);
		int* operator[](const int rhs);
		~matrix();
		int count_col() const {return num_col;};
		int count_str() const {return num_str;};
		int m_type() {return type;};
		T get_val(int str , int col) const {return mrx[str][col];};
		int fill_M();
		int print_M();
		void put_M(int str , int col , T val) const {mrx[str][col] = val;};
		matrix<T> transpotion ();
		//T minor_T(int str , int col);
		T determinate();
		//matrix<T> reverse(matrix A);
		void negate();
};

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix& rhs)
{
	matrix(rhs.count_str(), rhs.count_col());
	for (int i = 0 ; i < rhs.count_str() ; i++)
		for (int j = 0 ; j < rhs.count_col() ; j++)
			mrx[i][j] = rhs.get_val(i , j);
	num_col = rhs.count_col();
	num_str = rhs.count_str();
	count = rhs.count_col() * rhs.count_str();
	type = rhs.type;
	return *this;
};

template<typename T>
matrix<T>& matrix<T>::operator+(const matrix& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] += rhs.get_val(i , j);
	return *this;
};

template<typename T>
matrix<T>& matrix<T>::operator-(const matrix& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] -= rhs.get_val(i , j);
	return *this;
};

template<typename T>
matrix<T>& matrix<T>::operator*(const matrix& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] = mrx[i][j] * rhs.get_val(i , j);
	return *this;
};

template<typename T>
int* matrix<T>::operator[](const int rhs)
{
	assert(rhs >= 0);
	assert(rhs < num_str);
	int* str = new T [num_str];
	for (int i = 0 ; i < num_col ; i++)
		str[i] = mrx[rhs][i];
	return str;
};

template<typename T>
matrix<T> matrix<T>::operator[](const matrix& rhs)
{
	assert(num_str == rhs.count_col());
	int sum = 0;
	matrix result(num_str , rhs.count_col());
	assert(num_str == rhs.count_col());
	for (int i = 0 ; i < num_str ; i++)
	{
		for(int j = 0 ; j < rhs.count_col() ; j++)
		{
			for (int k = 0 ; k < num_col ; k++)
				sum = sum + mrx[i][k] * rhs.get_val(k , j);
			result.put_M(i , j , sum);
			sum = 0;
		};
	};
	return result;
};


template<typename T>
matrix<T>::matrix(const matrix& rhs)
{
	mrx = new T* [rhs.count_str()];
	for (int j = 0 ; j < rhs.count_str() ; ++j)
		mrx[j] = new T [rhs.count_col()];
	for (int i = 0 ; i < rhs.count_str() ; i++)
		for (int j = 0 ; j < rhs.count_col() ; j++)
			mrx[i][j] = rhs.get_val(i , j);
	num_col = rhs.count_col();
	num_str = rhs.count_str();
	count = rhs.count_col() * rhs.count_str();
	type = rhs.type;
};

template<typename T>
matrix<T>::matrix(int num_s , int num_c)
{
	mrx = new T* [num_s];
	for (int j = 0 ; j < num_s ; ++j)
		mrx[j] = new T [num_c];
	num_col = num_c;
	num_str = num_s;
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
};

template<typename T>
matrix<T>::matrix(int num)
{
	mrx = new T* [num];
	for (int i = 0 ; i < num ; ++i)
		mrx[i] = new T [num];
	num_col = num;
	num_str = num;
	count = num_col * num_str;
	type = 1;
};

template<typename T>
matrix<T>::~matrix()
{
	for (int i = 0 ; i < num_col ; ++i)
		delete[] mrx[i];
	delete[] mrx;
};

template<typename T>
int matrix<T>::fill_M()
{
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			std::cin >> mrx[i][j];
	return 1;
};

template<typename T>
int matrix<T>::print_M()
{
	std::cout << "count = " << count << "\n";
	std::cout << "num_col = " << num_col << "\n";
	std::cout << "num_str = " << num_str << "\n";
	std::cout << "type = " << type << "\n";
	for (int i = 0 ; i < num_str ; i++)
	{
		for (int j = 0 ; j < num_col ; j++)
			std::cout << mrx[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
	return 1;
};

template<typename T>
matrix<T> matrix<T>::transpotion()
{
	int num_s = count_str();
	int num_c = count_col();
	matrix<T> A_trans(num_s , num_c);
	for (int i = 0 ; i < num_s ; i++)
		for (int j = 0 ; j < num_c ; j++)
			A_trans.put_M(i , j , get_val(j , i));
	return A_trans;
};

template<typename T>
void matrix<T>::negate()
{
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] = (-1) * mrx[i][j];
}

template<typename T>
T matrix<T>::determinate()
{
	assert(num_str == num_col);
	if (mrx[0][0] == 0)
		return 0;
	matrix<T> L(num_str);
	matrix<T> U(num_str);
	T sum1 = 0;
	T sum2 = 0;
	T det = 1;
	for (int j = 0 ; j < num_str ; j++)
	{
		U.put_M(0 , j , mrx[0][j]);
		L.put_M(j , 0 , mrx[j][0] / U.get_val(0 , 0));
	};
	for (int i = 1 ; i < num_str ; i++)
		for (int j = i ; j < num_str ; j++)
		{
			for (int k = 0 ; k < i ; k++)
			{
				sum1 += L.get_val(i , k) * U.get_val(k , j);
				sum2 += L.get_val(j , k) * U.get_val(k , i);
			};
			U.put_M(i , j , mrx[i][j] - sum1);
			if (U.get_val(i , j) == 0)
				return 0;
			L.put_M(j , i , (mrx[j][i] - sum2) / U.get_val(i , i));
			sum1 = 0;
			sum2 = 0;
		};
	for (int i = 0 ; i < num_str ; i++)
		det = det * U.get_val(i , i);
	return det;
};

int main()
{
	int size = 0;
	std::cin >> size;
	matrix<float> test_1(size);
	test_1.fill_M();
	float det = test_1.determinate();
	std::cout << det << '\n';
	return 0;
}