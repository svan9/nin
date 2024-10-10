#pragma once

#include "config.hpp"

namespace nin {
	template<typename T>
	class Primitive {
	private:
		T _M_val;
	public:
		////////////////////////////////////////////////////////////
		Primitive() { }

		////////////////////////////////////////////////////////////
		Primitive(T&& _val): _M_val(_val) { }

		T& val() { return _M_val; }
	};

	class String {
	private:
		const char* _M_val;
		size_t _M_size;
	public:
		////////////////////////////////////////////////////////////
		String() { }

		////////////////////////////////////////////////////////////
		String(const char* cstr): _M_val(cstr), _M_size(strlen(cstr)-1) { }

		////////////////////////////////////////////////////////////
		String(const char* cstr, size_t _size): _M_val(cstr), _M_size(_size) { }

		////////////////////////////////////////////////////////////
		const char* val() { return _M_val; }

		////////////////////////////////////////////////////////////
		const char* c_str() { 
			char* buffer = new char[_M_size+1];
			memcpy(buffer, _M_val, _M_size);
			buffer[_M_size] = '\0';
			return buffer;
		}

		////////////////////////////////////////////////////////////
		size_t size() { return _M_size; }
	};

	typedef Primitive<int>     Integer;
	typedef Primitive<double>  Double;
	typedef Primitive<float>   Float;
}