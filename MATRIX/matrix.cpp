#include <iostream>
#include <iomanip>
#include <assert.h>

#define DBL_EPSILON 0.0000001



namespace Matrix_Ilab{


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
		//matrix<T>(int num_str , int num_col , T val = T{});
		template <typename It>
		matrix<T>(int cols, int rows, It start, It fin);
		matrix(const matrix& rhs);
		~matrix();
		matrix<T>& operator=(const matrix& rhs);
		matrix<T>& operator+(const matrix& rhs);
		matrix<T>& operator-(const matrix& rhs);
		matrix<T>& operator*(const matrix& rhs);
		matrix<T>& operator+=(const matrix& rhs);
		matrix<T>& operator-=(const matrix& rhs);
		matrix<T>& operator*=(const matrix& rhs);
		bool operator==(const matrix& rhs);
		bool operator!=(const matrix& rhs);
		matrix<T> operator[](const matrix& rhs);
		int* operator[](const int rhs);
		int count_col() const {return num_col;};
		int count_str() const {return num_str;};
		int m_type() {return type;};
		T get_val(int str , int col) const {return mrx[str][col];};
		void put_M(int str , int col , T val) const {mrx[str][col] = val;};
		void swap_rows(int row_1 , int row_2);
		void sub_rows(int row_1 , int row_2);
		void row_k(int row , float k);
		void fill_M();
		void fill_M_rand();
		void print_M();
		void negate();
		matrix<T> transpotion ();
		T determinate();
		//T minor_T(int str , int col);
		//matrix<T> reverse(matrix A);
};

template<typename T>
void swap(T* per_1 , T* per_2);

template<typename T>
void iszero(T* per);

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
}

template<typename T>
matrix<T>& matrix<T>::operator+(const matrix& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	matrix<T> buf = *this;
	buf += rhs;
	return buf;
}

template<typename T>
matrix<T>& matrix<T>::operator-(const matrix& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	matrix<T> buf = *this;
	buf -= rhs;
	return buf;
}

template<typename T>
matrix<T>& matrix<T>::operator*(const matrix& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	matrix<T> buf = *this;
	buf *= rhs;
	return buf;
}

template<typename T>
int* matrix<T>::operator[](const int rhs)
{
	assert(rhs >= 0);
	assert(rhs < num_str);
	int* str = new T [num_str];
	for (int i = 0 ; i < num_col ; i++)
		str[i] = mrx[rhs][i];
	return str;
}

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
}

template<typename T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] += rhs.get_val(i , j);
	return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator-=(const matrix<T>& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] -= rhs.get_val(i , j);
	return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator*=(const matrix<T>& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			mrx[i][j] *= rhs.get_val(i , j);
	return *this;
}

template <typename T>
bool matrix<T>::operator==(const matrix<T>& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
			if (mrx[i][j] != rhs.get_val(i , j))
				return 0;
	return 1;
}

template <typename T>
bool matrix<T>::operator!=(const matrix<T>& rhs)
{
	assert(num_col == rhs.count_col());
	assert(num_str == rhs.count_str());
	if (*this == rhs)
		return 0;
	return 1;
}

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
}

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
	mrx = new T* [num_s];
	for (int j = 0 ; j < num_s ; ++j)
		mrx[j] = new T [num_c];
	num_col = num_c;
	num_str = num_s;
	count = num_col * num_str;
	(num_col == num_str) ? type = 1 : type = 0;
	for (int i = 0 ; i < num_str ; ++i)
		for (int j = 0 ; j < num_col ; ++j)
		{
			mrx[i][j] = *start;
			start++;
		};
}

template<typename T>
matrix<T>::~matrix()
{
	for (int i = 0 ; i < num_col ; ++i)
		delete[] mrx[i];
	delete[] mrx;
}

template<typename T>
void matrix<T>::fill_M()
{
	for (int i = 0 ; i < num_str ; i++)
	{
		for (int j = 0 ; j < num_col ; j++)
			std::cin >> mrx[i][j];
	}
}

template<typename T>
void matrix<T>::fill_M_rand()
{
	for (int i = 0 ; i < num_str ; i++)
		for (int j = 0 ; j < num_col ; j++)
			mrx[i][j] = ((rand() % 10) - 5);
}

template<typename T>
void matrix<T>::print_M()
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
}

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
}

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
	matrix copy = *this;
	T det = 1;
	for (int i = 0 ; i < num_str ; i++)
	{
		T max = copy.get_val(i , i);
		int point = i;
		int num_s = i;
		while (point < num_str)
		{
			if (copy.get_val(point , i) != 0)
			{
				max = copy.get_val(point , i);
				num_s = point;
				break;
			};
			point++;
		};
		if (max == 0)
			return 0;
		for (int j = i ; j < num_str ; j++)
			if ((abs(copy.get_val(j , i)) > abs(max)) && (copy.get_val(j , i) != 0))
			{
				max = copy.get_val(j , i);
				num_s = j;
			};
		copy.swap_rows(num_s , i);
		det = det * copy.get_val(i , i);
		for (int j = i ; j < num_str ; ++j)
		{
			if ((j == i) || (copy.get_val(j , i) == 0))
				continue;
			T per = copy.get_val(j , i) / copy.get_val(i , i);
			T* row = new T[num_col - i];
			for (int l = 0 ; l < num_col - i ; l++)
				row[l] = copy.get_val(i , l + i);
			copy.row_k(i , per);
			copy.print_M();
			copy.sub_rows(j , i);
			copy.print_M();
			for (int l = 0 ; l < num_col - i ; l++)
				copy.put_M(i , l + i , row[l]);
			delete[] row;
		};
	};
	iszero(&det);
	return det;
}

template<typename T>
void matrix<T>::swap_rows(int row_1 , int row_2)
{
	assert(row_1 < num_str);
	assert(row_2 < num_str);
	for (int i = 0 ; i < num_col ; i++)
		swap(&mrx[row_1][i] , &mrx[row_2][i]);
}

template<typename T>
void swap(T* per_1 , T* per_2)
{
	T per = *per_1;
	*per_1 = *per_2;
	*per_2 = per;
}

template<typename T>
void matrix<T>::sub_rows(int row_1 , int row_2)
{
	assert(row_1 < num_str);
	assert(row_2 < num_str);
	for (int i = 0 ; i < num_col ; i++)
		mrx[row_1][i] = mrx[row_1][i] - mrx[row_2][i];
}

template<typename T>
void matrix<T>::row_k(int row , float k)
{
	assert(row < num_str);
	for (int i = 0 ; i < num_col ; i++)
		mrx[row][i] = mrx[row][i] * k;
}

template<typename T>
void iszero(T* per)
{
	if (abs(*per) <= DBL_EPSILON)
		*per = 0;
}

}

using namespace Matrix_Ilab;

int main()
{
	int size = 0;
	std::cin >> size;
	matrix<float> test_1(size);
	test_1.fill_M();
	float det = test_1.determinate();
	std::cout << det << "\n";
	return 0;
};