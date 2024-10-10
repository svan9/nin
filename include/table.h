#pragma once
#include "config.hpp"
#include "types.h"
#include "state.h"
#include "stack.h"

namespace nin {	
	class Table {
	private:
		Stack/*<StateObject>*/ st;
		size_t size;
	public:
		////////////////////////////////////////////////////////////
		Table() { }
		
		////////////////////////////////////////////////////////////
		StateObject* at(int idx) {
			return st.at<StateObject>(idx);
		}

		////////////////////////////////////////////////////////////
		StateObject* at(const char* name) {
			for (int i = 0; i < st.size(); i++) {
				StateObject* so = st.at<StateObject>(i);
				if (so->is(name)) { return so; }
			}
			return nullptr;
		}
	};
}