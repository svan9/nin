#include "stack.h"

void* nin::Stack::begin() {
	return this+_M_begin;
}

void* nin::Stack::end() {
	return this+_M_end;
}

void nin::Stack::begin(void* v) {
	_M_begin = ((size_t)v-(size_t)this);
}

void nin::Stack::end(void* v) {
	_M_end = ((size_t)v-(size_t)this);
}

void nin::Stack::shift_end() {
	_M_end += sizeof(void*);
}

void nin::Stack::unshift_end() {
	_M_end -= sizeof(void*);
	if (_M_end < _M_begin) {
		_M_end += sizeof(void*);
	}
}

void nin::Stack::begin(size_t v) {
	begin((void*)v);
}

void nin::Stack::end(size_t v) {
	end((void*)v);
}

nin::Stack::Stack() {
	begin(new void*[DEFAULT_ALLOC_SIZE]);
	end(begin());
	capacity = DEFAULT_ALLOC_SIZE;
}

void nin::Stack::resize(size_t _new_size) {
	size_t __ssize = size();
	void* __temp_begin = new void*[_new_size];
	memmove(__temp_begin, begin(), capacity);
	free(begin());
	begin(__temp_begin);
	end(__ssize + _M_begin);
	capacity = _new_size;
}

size_t nin::Stack::size() {
	return (size_t)_M_end - (size_t)_M_begin;
}

void nin::Stack::drop_sbs() {
	size_t __ssize = size();
	capacity = __ssize;
	void* __temp_begin = new void*[__ssize];
	memmove(__temp_begin, begin(), __ssize);
	free(begin());
	begin(__temp_begin);
	end(__temp_begin+__ssize);
}


template <typename T>
inline T *nin::Stack::at(int idx) {
	size_t index = idx;
	if (idx < 0) {
		index = size() + idx;
	} index %= size(); index--;
	return (T*)(begin()+(sizeof(void*)*index));
}

template <typename T>
void nin::Stack::push(T&& item) {
	if (size()+1 > capacity) {
		resize(size()*DEFAULT_ALLOC_MULT);
	}
	memcpy(end(), &item, sizeof(void*));
	shift_end();
}