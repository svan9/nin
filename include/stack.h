#pragma once

#include "config.hpp"

namespace nin {

class Stack {
private:
	poffset _M_begin, _M_end;
	size_t capacity;
public:
	////////////////////////////////////////////////////////////
	Stack();

	////////////////////////////////////////////////////////////
	void resize(size_t _new_size);

	////////////////////////////////////////////////////////////
	void reserve(size_t _size);

	////////////////////////////////////////////////////////////
	///@brief
	///@param idx can be negative for use index from top (starts with 1 & -1)
	template<typename T>
	T* at(int idx);

	////////////////////////////////////////////////////////////
	///@brief resize size by size / capacity == size
	void drop_sbs();

	////////////////////////////////////////////////////////////
	size_t size();
	
	////////////////////////////////////////////////////////////
	void* begin();

	////////////////////////////////////////////////////////////
	void* end();

	////////////////////////////////////////////////////////////
	void begin(void*);

	////////////////////////////////////////////////////////////
	void end(void*);

	////////////////////////////////////////////////////////////
	void nin::Stack::begin(size_t);

	////////////////////////////////////////////////////////////
	void nin::Stack::end(size_t);

	////////////////////////////////////////////////////////////
	void shift_end();

	////////////////////////////////////////////////////////////
	void unshift_end();
	
	////////////////////////////////////////////////////////////
	template <typename T>
	void nin::Stack::push(T&& item);
	
};

};