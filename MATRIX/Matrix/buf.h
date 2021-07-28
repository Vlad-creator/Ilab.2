#pragma once


namespace bfr
{

template<typename T>
void copy_construct(T* p , T& val)
{
	new (p) T (val);
}

template<class T>
void destroy(T* p)
{
	p->~T();
}

template<typename iter>
void destroy(iter start , iter end)
{
	while(start++ != end)
		destroy(&*start);
}


template<typename T>
class buffer
{
	buffer<T>& operator=(const buffer& rhs) = delete;
	buffer<T>(const buffer& rhs) = delete;

protected:
	T* buf;
	size_t size_;
	size_t used_;

	buffer<T>();
	buffer<T>(size_t size);

	void swap(buffer& rhs);

	~buffer();
};

template<typename T>
buffer<T>::buffer(): size_(0) , used_(0)
{
	buf = nullptr;
}

template<typename T>
buffer<T>::buffer(size_t size): size_(size) , used_(0)
{
	buf = ((size == 0) ? nullptr : 
			static_cast<T*>(::operator new(sizeof(T) * size)));
}

template<typename T>
buffer<T>::~buffer()
{
	destroy(buf , buf + used_);
	::operator delete(buf); 
}

template<typename T>
void buffer<T>::swap(buffer& rhs)
{
	std::swap(buf , rhs.buf);
	std::swap(size_ , rhs.size_);
	std::swap(used_ , rhs.used_);
}

};