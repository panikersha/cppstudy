#include "pch.h"
#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy
#include <iostream>
using namespace std;

struct IntArray
{
	explicit IntArray(size_t size):size_(size), data_(new int[size])
	{
		for (size_t i = 0; i != size; ++i)
			data_[i] = 0;
	}
	IntArray(IntArray const &a):size_(a.size_), data_(new int[size_])
	{
		for (size_t i = 0; i != size; ++i)
			data_[i] = a.data_[i];
	}
	~IntArray()
		{
		delete [] data_;
		}
	void swap(IntArray &a)
	{
		std::swap(size_, a.size_);
		std::swap(data_, a.data_);
	}
	IntArray & operator=(IntArray&a)
	{
		if(this!=&a)
		{
			IntArray(a).swap(*this);
			return *this;
		}
	}
	size_t size() const
	{
		return size_;
	}
	int & get(size_t i)
	{
		return data_[i];
	}

	void resize (size_t nsize)
	{
		IntArray t(nsize);
		size_t n = nsize > size_ ? size_ : nsize;
		for(size_t i = 0; i!= n;++i)
			t.data_[i] = data_[i];
		swap(t);
	}

private:
	size_t size_;
	int * data_;
};
