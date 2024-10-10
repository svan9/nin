#pragma once

#include "config.hpp"
#include "stack.h"
#include "types.h"

namespace nin {

enum StateObjectType {
	TString, TInteger, TDouble, TFloat, TTable, TFunction
};

class Table;

class StateObject {
private:
	StateObjectType type;
	const char* name;
	void* object;
public:
	////////////////////////////////////////////////////////////
	StateObject();

	////////////////////////////////////////////////////////////
	bool is(const char* name);

	////////////////////////////////////////////////////////////
	template<typename T>
	bool is(T type);

	////////////////////////////////////////////////////////////
	template<class>
	bool is<Integer>();
	
	////////////////////////////////////////////////////////////
	template<class>
	bool is<String>();
	
	////////////////////////////////////////////////////////////
	template<class>
	bool is<String>();
	
	////////////////////////////////////////////////////////////
	template<class>
	bool is<Double>();
	
	////////////////////////////////////////////////////////////
	template<class>
	bool is<Float>();
	
	////////////////////////////////////////////////////////////
	template<class>
	bool is<runtime_function>();

	////////////////////////////////////////////////////////////
	template<typename T>
	T* get();
};


class State {
private:
	Stack st;
public:
	////////////////////////////////////////////////////////////
	State();

	////////////////////////////////////////////////////////////
	template<typename T>
	void push(T&& val);

	////////////////////////////////////////////////////////////
	///@brief
	///@param idx can be negative for use index from top (starts with 1 & -1)
	template<typename T>
	T at(int idx);

	////////////////////////////////////////////////////////////
	void pop(size_t count = 1);

	////////////////////////////////////////////////////////////
	size_t call(size_t argc=0, bool retval=false);

	////////////////////////////////////////////////////////////
	void find(const char* name);
};

template <typename T>
inline bool StateObject::is(T type) {
	return false;
}
template<>
inline bool StateObject::is<Integer>() {
	return type == StateObjectType::TInteger;
}
template<>
inline bool StateObject::is<String>() {
	return type == StateObjectType::TString;
}
template<>
inline bool StateObject::is<Double>() {
	return type == StateObjectType::TDouble;
}
template<>
inline bool StateObject::is<Float>() {
	return type == StateObjectType::TFloat;
}
template<>
inline bool StateObject::is<Table>() {
	return type == StateObjectType::TTable;
}
template<>
inline bool StateObject::is<runtime_function>() {
	return type == StateObjectType::TFunction;
}

}