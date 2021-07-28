#pragma once

#include "MatrBuf.h"

namespace bfr
{

template<typename T>
class matrix : private MatrBuf<T>
{
	using MatrBuf<T>::buf;
	using MatrBuf<T>::size_;
	using MatrBuf<T>::used_;
	using MatrBuf<T>::MBuf;
	using MatrBuf<T>::rows_;
	using MatrBuf<T>::columns_;

	struct ProxyRow
	{
		T* row;
		T& operator[](size_t id) {return row[id];};
		const T& operator[](size_t id) const {return row[id];};
	};

public:
	matrix<T>(size_t rows = 0 , size_t columns = 0 , T val = T{});
	matrix& operator=(const matrix& rhs);
	matrix(const matrix& rhs);
	matrix(matrix&& rhs);
	matrix& operator=(matrix&& rhs);
	template<typename U>
	matrix(const matrix<U>& rhs);
	template <typename It>
	matrix(size_t rows, size_t columns, It start , It fin);
	~matrix() {};

	ProxyRow operator[](size_t id);
	const ProxyRow operator[](size_t id) const; 

	matrix<T> operator+(const matrix& rhs) const;
	matrix<T> operator-(const matrix& rhs) const;
	matrix<T> operator*(const matrix& rhs) const;
	matrix<T>& operator+=(const matrix& rhs);
	matrix<T>& operator-=(const matrix& rhs);
	bool operator==(const matrix& rhs) const;
	bool operator!=(const matrix& rhs) const;

	void print() const;
	size_t get_rows() const {return rows_;};
	size_t get_columns() const {return columns_;};
	void swap_rows(size_t id_1 , size_t id_2);
	void row_k(size_t id , T k);
	void negate();
	matrix<T> transpose();

	void sub_row_k(size_t id_1 , size_t id_2 , T val = 1); //id_1 - id_2 * k

	T determinant();
};

template<typename T>
std::ostream& operator<<(std::ostream& out , const matrix<T>& rhs)
{
	out << "rows = " << rhs.get_rows() << std::endl;
	out << "columns = " << rhs.get_columns() << std::endl;
	for (int i = 0 ; i < rhs.get_rows() ; ++i)
	{
		for (int j = 0 ; j < rhs.get_columns() ; ++j)
			out << rhs[i][j] << " ";
		out <<"\n";
	}
	out << std::endl;
	return out;
}

template<typename T>
std::istream& operator>>(std::istream& in , matrix<T>& rhs)
{
	for (int i = 0 ; i < rhs.get_rows() ; ++i)
	{
		for (int j = 0 ; j < rhs.get_columns() ; ++j)
			in >> rhs[i][j];
	}
	return in;
}

template<typename T>
typename matrix<T>::ProxyRow matrix<T>::operator[](size_t id)
{
	ProxyRow tmp;
	tmp.row = MBuf[id];
	return tmp;
}	

template<typename T>
const typename matrix<T>::ProxyRow matrix<T>::operator[](size_t id) const
{
	ProxyRow tmp;
	tmp.row = MBuf[id];
	return tmp;
}

template<typename T>
matrix<T>::matrix(size_t rows , size_t columns , T val): MatrBuf<T>(rows , columns) 
{
	for (size_t i = 0 ; i < rows ; ++i)
		for (size_t j = 0 ; j < columns ; ++j)
			MBuf[i][j] = val;
	/*std::cout << "ctor" << std::endl;*/
}

template <typename T>
template <typename It>
matrix<T>::matrix(size_t rows , size_t columns , It start , It fin): MatrBuf<T>(rows , columns)
{
	if (std::distance(start , fin) != rows * columns)
	{
		throw std::logic_error{"sizeof container != sizeof matrix"};
	}

	for (int i = 0 ; i < rows_ ; ++i)
		for (int j = 0 ; j < columns_ ; ++j)
		{
			MBuf[i][j] = *start;
			start++;
		}
}

template<typename T>
matrix<T>::matrix(const matrix& rhs): MatrBuf<T>(rhs.rows_ , rhs.columns_)
{
	for (int used = 0 ; used < (rhs.rows_ * rhs.columns_) ; ++used)
	{
		copy_construct<T>(buf + used , rhs.buf[used]);
		used_++;
	}
	//std::cout << "copy ctor" << std::endl;
}

template<typename T>
template<typename U>
matrix<T>::matrix(const matrix<U>& rhs): MatrBuf<T>(rhs.get_rows() , rhs.get_columns())
{
	for (size_t i = 0 ; i < rows_ ; ++i)
		for (size_t j = 0 ; j < columns_ ; ++j)
	{
		buf[i * columns_ + j] = rhs[i][j];
		used_++;
	}
}

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix& rhs)
{
	matrix tmp(rhs);
	MatrBuf<T>::swap(tmp);
	//std::cout << "copy assign" << std::endl;
	return *this;
}

template<typename T>
matrix<T>::matrix(matrix&& rhs): MatrBuf<T>()
{
	MatrBuf<T>::swap(rhs);
	//std::cout << "move ctor" << std::endl;
}

template<typename T>
matrix<T>& matrix<T>::operator=(matrix&& rhs)
{
	matrix tmp(std::move(rhs));
	MatrBuf<T>::swap(tmp);
	//std::cout << "move assign" << std::endl;
	return *this;
}

template<typename T>
void matrix<T>::print() const
{
	std::cout << "rows - " << rows_ << std::endl;
	std::cout << "columns - " << columns_ << std::endl;

	for (size_t i = 0 ; i < rows_ ; ++i)
	{
		for (size_t j = 0 ; j < columns_ ; ++j)
			std::cout << MBuf[i][j] << " ";
		std::cout << std::endl;
	}
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix& rhs) const
{
	if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
	{
		throw (std::logic_error{"these matrices cannot be added"});
	}
	else
	{
		matrix<T> res(rows_ , columns_);
		for (size_t i = 0 ; i < res.rows_ ; ++i)
			for (size_t j = 0 ; j < res.columns_ ; ++j)
				res.MBuf[i][j] = MBuf[i][j] + rhs.MBuf[i][j];
		return res;
	}
}

template<typename T>
matrix<T> matrix<T>::operator-(const matrix& rhs) const
{
	if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
	{
		throw (std::logic_error{"these matrices cannot be sub"});
	}
	else
	{
		matrix<T> res(rows_ , columns_);
		for (size_t i = 0 ; i < res.rows_ ; ++i)
			for (size_t j = 0 ; j < res.columns_ ; ++j)
				res.MBuf[i][j] = MBuf[i][j] - rhs.MBuf[i][j];
		return res;
	}
}

template<typename T>
matrix<T> matrix<T>::operator*(const matrix& rhs) const
{
	if ((columns_ != rhs.rows_))
	{
		throw (std::logic_error{"these matrices cannot be product"});
	}
	else
	{
		matrix<T> res(rows_ , rhs.columns_);
		T sum = 0;
		for (size_t i = 0 ; i < rows_ ; ++i)
		{
			T* res_per = res.MBuf[i];
			for (size_t j = 0 ; j < columns_ ; ++j)
			{
				const T* row_rhs = rhs.MBuf[j];
				float per_lhs = MBuf[i][j];

				for (int k = 0 ; k < res.columns_ ; ++k)
					res_per[k] += row_rhs[k] * per_lhs;
			}
		}
		return res;
	}
}

template<typename T>
matrix<T>& matrix<T>::operator+=(const matrix& rhs)
{
	if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
	{
		throw (std::logic_error{"these matrices cannot be added"});
	}
	else
	{
		for (size_t i = 0 ; i < rows_ ; ++i)
			for (size_t j = 0 ; j < columns_ ; ++j)
				MBuf[i][j] += rhs.MBuf[i][j];
		return *this;
	}
}

template<typename T>
matrix<T>& matrix<T>::operator-=(const matrix& rhs)
{	
	if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
	{
		throw (std::logic_error{"these matrices cannot be sub"});
	}
	else
	{
		for (size_t i = 0 ; i < rows_ ; ++i)
			for (size_t j = 0 ; j < columns_ ; ++j)
				MBuf[i][j] -= rhs.MBuf[i][j];
		return *this;
	}
}

template<typename T>
bool matrix<T>::operator==(const matrix& rhs) const
{
	if ((rows_ != rhs.rows_) || (columns_ != rhs.columns_))
	{
		return false;
	}
	else
	{
		for (size_t i = 0 ; i < rows_ ; ++i)
			for (size_t j = 0 ; j < columns_ ; ++j)
				if(MBuf[i][j] != rhs.MBuf[i][j])
					return false;
	}
	return true;
}

template<typename T>
bool matrix<T>::operator!=(const matrix& rhs) const
{
	bool res = (*this == rhs);
	return (!res);
}

template<typename T>
void matrix<T>::swap_rows(size_t id_1 , size_t id_2)
{
	if ((id_1 < 0) || (id_1 >= rows_) || (id_2 < 0) || (id_2 >= rows_))
	{
		throw std::logic_error{"Wrong size"};
	}
	std::swap(MBuf[id_1] , MBuf[id_2]);
}

template<typename T>
void matrix<T>::row_k(size_t id , T k)
{
	if ((id < 0) || (id >= rows_))
	{
		throw std::logic_error{"Wrong size"};
	}
	for (int i = 0 ; i < columns_ ; ++i)
		MBuf[id][i] = MBuf[id][i] * k;
}

template<typename T>
void matrix<T>::sub_row_k(size_t id_1 , size_t id_2 , T val)
{
	if ((id_1 < 0) || (id_1 >= rows_) || (id_2 < 0) || (id_2 >= rows_))
	{
		throw std::logic_error{"Wrong size"};
	}
	for (int i = 0 ; i < columns_ ; ++i)
		MBuf[id_1][i] -= MBuf[id_2][i] * val;
}

template<typename T>
T matrix<T>::determinant()
{
	if (columns_ != rows_)
	{
		throw std::logic_error{"determinant cannot be taken"};
	}
	matrix<long double> copy(*this);
	double det = 1;
	for (size_t i = 0 ; i < rows_ - 1; ++i)
	{
		long double max = copy[i][i];
		size_t num_s = i;
		for (size_t j = i + 1 ; j < rows_ ; ++j)
			if ((std::abs(copy[j][i]) > std::abs(max)))
			{
				max = copy[j][i];
				num_s = j;
			}
		if (max == 0)
			return 0;
		if (num_s != i)
		{
			copy.swap_rows(num_s , i);
			det = det * (-1);
		}
		det = det * copy[i][i];
		 for (size_t j = i + 1 ; j < rows_ ; ++j)
		 {
		 	long double per = copy[j][i] / max;
		 	copy.sub_row_k(j , i , per);
		 }
	}
	det *= copy[rows_ - 1][columns_ - 1];
	det = static_cast<T>(det);
	return det;
}

template<typename T>
matrix<T> matrix<T>::transpose()
{
	matrix<T> A_trans(columns_ , rows_);
	for (size_t i = 0 ; i < columns_ ; ++i)
		for (size_t j = 0 ; j < rows_ ; ++j)
			A_trans[i][j] = MBuf[j][i];
	return A_trans;
}

template<typename T>
void matrix<T>::negate()
{
	for (size_t i = 0 ; i < rows_ ; ++i)
		for (size_t j = 0 ; j < columns_ ; ++j)
			MBuf[i][j] = (-1) * MBuf[i][j];
}

}