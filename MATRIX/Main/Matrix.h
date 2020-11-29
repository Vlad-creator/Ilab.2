#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cfloat>

namespace {

//Опредение равно ли число нулю
template<typename T>
void iszero(T* per)
{
	if (abs(*per) <= DBL_EPSILON)
		*per = 0;
}

}

namespace Matrix_Ilab{

template<typename T>
class matrix
{
		int type;//Если 0 - прямоугольная матрица , 1 - квадратная матрица
		int num_col;
		int num_str;
		int count;
		T** mrx;
	public:
		//matrix<T>(int num_str , int num_col , T val = T{});
		matrix<T>(int num_str , int num_col);
		matrix<T>(int num);
		template <typename It>
		matrix<T>(int cols, int rows, It start, It fin);
		template <typename It>
		matrix<T>(int num , It start , It fin);
		template <typename U>
		matrix(const matrix<U>& rhs);
		matrix(const matrix& rhs);
		void cleanup();
		~matrix();

		matrix<T>& operator=(const matrix& rhs);
		matrix<T> operator+(const matrix& rhs);
		matrix<T> operator-(const matrix& rhs);
		matrix<T> operator*(const matrix& rhs);
		matrix<T>& operator+=(const matrix& rhs);
		matrix<T>& operator-=(const matrix& rhs);
		matrix<T>& operator*=(const matrix& rhs);
		bool operator==(const matrix& rhs);
		bool operator!=(const matrix& rhs);
		T* operator[](const int rhs);

		matrix<T> product(const matrix& rhs);
		int count_col() const {return num_col;};
		int count_str() const {return num_str;};
		int m_type() const {return type;};
		T get_val(int str , int col) const {return mrx[str][col];};
		void put_M(int str , int col , T val) const {mrx[str][col] = val;};
		void swap_rows(int row_1 , int row_2);
		void sub_rows_k(int row_1 , int row_2, T k = 1);//row_1 - row_2
		void row_k(int row , float k);
		void fill_M();
		void fill_M_rand();
		void print_M();
		void negate();
		matrix<T> transpotion ();
		long double determinate();
		//T minor_T(int str , int col);
		//matrix<T> reverse(matrix A);
};

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& rhs)
{
	if (this == &rhs)
		return *this;

	if ((num_str != rhs.num_str) || (num_col != rhs.num_col))
	{
		if (mrx)
			cleanup();
		num_str = rhs.num_str;
		num_col = rhs.num_col;
		mrx = new T* [num_str];
		for (int i = 0 ; i < num_str ; ++i)
			mrx[i] = new T [num_col];
		count = rhs.num_col * rhs.num_str;
		type = rhs.type;
	};

	for (int i = 0 ; i < num_str ; ++i)
	{
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] = rhs.mrx[i][j];
	};

	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);

	matrix<T> buf = *this;
	buf += rhs;
	return buf;
}

template<typename T>
matrix<T> matrix<T>::operator-(const matrix& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);

	matrix<T> buf = *this;
	buf -= rhs;
	return buf;
}

//Умножает матрицы как логично
template<typename T>
matrix<T> matrix<T>::operator*(const matrix& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);

	matrix<T> buf = *this;
	buf *= rhs;
	return buf;
}

template<typename T>
T* matrix<T>::operator[](const int rhs)
{
	assert(rhs >= 0);
	assert(rhs < num_str);

	return mrx[rhs];
}

//Умножает матрицы как надо это делать правильно
template<typename T>
matrix<T> matrix<T>::product(const matrix& rhs)
{
	assert(num_col == rhs.num_str);

	int sum = 0;
	matrix result(num_str , rhs.num_col);
	for (int i = 0 ; i < num_str ; i++)
	{
		for(int j = 0 ; j < rhs.num_col ; j++)
		{
			for (int k = 0 ; k < num_col ; k++)
				sum = sum + mrx[i][k] * rhs.mrx[k][j];
			result.put_M(i , j , sum);
			sum = 0;
		};
	};
	return result;
}

template<typename T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] += rhs.mrx[i][j];
	return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator-=(const matrix<T>& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] -= rhs.mrx[i][j];
	return *this;
}

//Умножает матрицы как логично
template<typename T>
matrix<T>& matrix<T>::operator*=(const matrix<T>& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);

	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] *= rhs.mrx[i][j];
	return *this;
}

template <typename T>
bool matrix<T>::operator==(const matrix<T>& rhs)
{
	assert(num_col == rhs.num_col);
	assert(num_str == rhs.num_str);

	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			if (mrx[i][j] != rhs.mrx[i][j])
				return false;
	return true;
}

template <typename T>
bool matrix<T>::operator!=(const matrix<T>& rhs)
{
	if (*this == rhs)
		return 0;
	return 1;
}

template<typename T>
matrix<T>::matrix(const matrix& rhs)
{
	mrx = new T* [rhs.num_str];
	for (int j = 0 ; j < rhs.num_str ; ++j)
		mrx[j] = new T [rhs.num_col];
	for (int i = 0 ; i < rhs.num_str ; i++)
		for (int j = 0 ; j < rhs.num_col ; j++)
			mrx[i][j] = rhs.mrx[i][j];
	num_col = rhs.num_col;
	num_str = rhs.num_str;
	count = rhs.num_col * rhs.num_str;
	type = rhs.type;
}

template<typename T>
matrix<T>::matrix(int num_s , int num_c)
{
	num_col = num_c;
	num_str = num_s;
	mrx = new T* [num_str];
	for (int j = 0 ; j < num_str ; ++j)
		mrx[j] = new T [num_col];
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
}

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
}

template <typename T>
template <typename It>
matrix<T>::matrix(int num_s , int num_c , It start , It fin)
{
	num_col = num_c;
	num_str = num_s;
	mrx = new T* [num_str];

	for (int j = 0 ; j < num_str ; ++j)
		mrx[j] = new T [num_col];
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
		{
			mrx[i][j] = *start;
			start++;
		};
}

template <typename T>
template <typename It>
matrix<T>::matrix(int num , It start , It fin)
{
	num_col = num;
	num_str = num;
	mrx = new T* [num];

	for (int j = 0 ; j < num ; ++j)
		mrx[j] = new T [num];
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
	for (int i = 0 ; i < num ; ++i)
		for (int j = 0 ; j < num ; ++j)
		{
			mrx[i][j] = *start;
			start++;
		};
}

template <typename T>
template <typename U>
matrix<T>::matrix(const matrix<U>& rhs)
{
	num_str = rhs.count_str();
	num_col = rhs.count_col();
	mrx = new T* [num_str];

	for (int i = 0 ; i < num_str ; ++i)
	{
		mrx[i] = new T [num_col];
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] = rhs.get_val(i , j);
	};
}

template<typename T>
matrix<T>::~matrix()
{
	cleanup();
}

template<typename T>
void matrix<T>::cleanup()
{
	for (int i = 0 ; i < num_str ; ++i)
		delete[] mrx[i];
	delete[] mrx;
}

//заполняет матрицу с потока ввода
template<typename T>
void matrix<T>::fill_M()
{
	for (int i = 0 ; i < num_str ; ++i)
	{
		for (int j = 0 ; j < num_col ; ++j)
			std::cin >> mrx[i][j];
	}
}

//заполняет матрицу случайными значениями
template<typename T>
void matrix<T>::fill_M_rand()
{
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] = ((rand() % 10) - 5);
}

//выводит на экран матрицу со всеми её данными
template<typename T>
void matrix<T>::print_M()
{
	std::cout << "count = " << count << "\n";
	std::cout << "num_col = " << num_col << "\n";
	std::cout << "num_str = " << num_str << "\n";
	std::cout << "type = " << type << "\n";

	for (int i = 0 ; i < num_str ; ++i)
	{
		for (int j = 0 ; j < num_col ; ++j)
			std::cout << mrx[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

//выполняет транспонирование матрицы
template<typename T>
matrix<T> matrix<T>::transpotion()
{
	int num_s = num_str;
	int num_c = num_col;
	matrix<T> A_trans(num_c , num_s);
	for (int i = 0 ; i < num_c ; i++)
		for (int j = 0 ; j < num_s ; j++)
			A_trans.put_M(i , j , mrx[j][i]);
	return A_trans;
}

//домножает матрицу на (-1)
template<typename T>
void matrix<T>::negate()
{
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] = (-1) * mrx[i][j];
}

//функция нахождения детерминанта
template<typename T>
long double matrix<T>::determinate()
{
	assert(type == 1);
	matrix<long double> copy = *this;
	long double det = 1;
	for (int i = 0 ; i < num_str - 1; i++)
	{
		long double max = copy.get_val(i , i);
		int num_s = i;
		for (int j = i + 1; j < num_str ; j++)
			if ((std::abs(copy.get_val(j , i)) > std::abs(max)))
			{
				max = copy.get_val(j , i);
				num_s = j;
			}
		if (max == 0)
			return 0;
		if (num_s != i)
		{
			copy.swap_rows(num_s , i);
			det = det * (-1);
		};
		//std::cout << "MAX: " << max << std::endl;
		det = det * copy.get_val(i , i);
		//std::cout << "DET: " << det << std::endl;
		 for (int j = i + 1 ; j < num_str ; ++j)
		 {
		 	long double per = copy[j][i] / max;
		 	copy.sub_rows_k(j , i , per);
		 }
	}
	det *= copy.get_val(num_str - 1, num_str - 1);
	::iszero(&det);
	static_cast<T>(det);
	return det;
}

//меняет местами две строки в матрице
template<typename T>
void matrix<T>::swap_rows(int row_1 , int row_2)
{
	assert(row_1 < num_str);
	assert(row_2 < num_str);

	for (int i = 0 ; i < num_col ; i++)
		std::swap(mrx[row_1][i] , mrx[row_2][i]);
}

//вычитает из row_1 row_2 умноженное на k
template<typename T>
void matrix<T>::sub_rows_k(int row_1 , int row_2, T k)
{
	assert(row_1 < num_str);
	assert(row_2 < num_str);

	for (int i = 0 ; i < num_col ; i++)
		mrx[row_1][i] = mrx[row_1][i] - k * mrx[row_2][i];
}

}
