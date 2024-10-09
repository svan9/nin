#include "state.h"

nin::State::State() { }

void nin::State::call() {
	//todo
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
