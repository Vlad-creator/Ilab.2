#pragma once

#include "buf.h"

namespace  bfr
{

template<typename T>
class MatrBuf : public buffer<T>
{
	MatrBuf& operator=(const MatrBuf& rhs) = delete;
	MatrBuf(const MatrBuf& rhs) = delete;

protected:
	using buffer<T>::buf;
	using buffer<T>::size_;
	using buffer<T>::used_;
	
	T** MBuf;
	size_t rows_;
	size_t columns_;

	MatrBuf<T>();
	MatrBuf<T>(size_t rows , size_t columns);

	void swap(MatrBuf& rhs);

	~MatrBuf();
};

template<typename T>
MatrBuf<T>::MatrBuf(size_t rows , size_t columns): buffer<T>(rows * columns) , 
												   rows_(rows) , columns_(columns) 
{
	MBuf = ((rows == 0) || (columns == 0)) ? nullptr : 	
		static_cast<T**>(::operator new (sizeof(T*) * (rows)));
	for (size_t i = 0 ; i < rows ; ++i)
	{
		MBuf[i] = (buf + i * columns_);
	}
}

template<typename T>
MatrBuf<T>::MatrBuf(): buffer<T>() , rows_(0) , columns_(0)
{
	MBuf = nullptr;
}

template<typename T>
void MatrBuf<T>::swap(MatrBuf& rhs)
{	
	buffer<T>::swap(rhs);
	std::swap(MBuf , rhs.MBuf);
	std::swap(rows_ , rhs.rows_);
	std::swap(columns_ , rhs.columns_);
}

template<typename T>
MatrBuf<T>::~MatrBuf()
{
	destroy(MBuf , MBuf + rows_);
	::operator delete(MBuf);
}


}