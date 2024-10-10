#include "state.h"

inline size_t
DefaultFunctionProcessor(nin::State* st) {
	
} 

nin::State::State() { }

size_t nin::State::call(size_t argc=0, bool retval=false) {
	StateObject* so = st.at<StateObject>(-1-argc);
	if (so->is<runtime_function>()) {
		auto fn = (*so->get<runtime_function>());
		return fn(this);
	}
}

void nin::State::find(const char *name) {
	// todo
}

template <typename T>
inline void nin::State::push(T &&val) {
	st.push(val);
}

template <typename T>
T nin::State::at(int idx) {
	return *st.at(idx);
}

void nin::State::pop(size_t count = 1) {
	for (int i = 0; i < count; ++i) { st.unshift_end(); }
}

nin::StateObject::StateObject() {
}

bool nin::StateObject::is(const char *name) {
	return this->name == name;
}

template <typename T>
inline T* nin::StateObject::get() {
	return static_cast<T*>(this->object);
}


