#pragma once
#include "config.hpp"
#include "types.h"
#include "state.h"

namespace nin {	
	typedef size_t(*runtime_function)(State*);
	// template<typename T>
	// class NinFunction {
	// 	friend class State;
	// private:
	// 	runtime_function processor;
	// public:
	// 	////////////////////////////////////////////////////////////
	// 	NinFunction() {}

	// };
	
	class BaseFunction {
	private:
		State* st;
		runtime_function processor;
	public:
		////////////////////////////////////////////////////////////
		BaseFunction() {}

		////////////////////////////////////////////////////////////
		BaseFunction(State* _st): st(_st) {}

		////////////////////////////////////////////////////////////
		BaseFunction(State* _st, const char* name): st(_st) {
			st->find(name);
			processor = st->at<runtime_function>(-1);
			st->pop();
		}

	protected:
		template<typename FmtT, typename ...ArgsT>
		void constuct(FmtT fmt, ArgsT... args) {
			st->push(fmt);
			constuct(args...);
		}

		template<typename FmtT>
		void constuct(FmtT fmt) {
			st->push(fmt);
			constuct();
		}

		void constuct() {
			st->push(processor);
			st->call();
		}
	};

	template<class>
	class Function;

	template<typename T, typename ...ARGS>
	class Function<T(ARGS...)> : public BaseFunction {
	public:
		////////////////////////////////////////////////////////////
		Function() {}

		////////////////////////////////////////////////////////////
		T operator()(ARGS... args) {
			constuct(args...);
			return this->st->at<T>(-1);
		}
	};

	template<typename ...ARGS>
	class Function<void(ARGS...)> : public BaseFunction {
	public:
		////////////////////////////////////////////////////////////
		Function() {}

		////////////////////////////////////////////////////////////
		void operator()(ARGS... args) {
			constuct(args...);
		}
	};

	template<typename T>
	class Function<T()> : public BaseFunction {
	public:
		////////////////////////////////////////////////////////////
		Function() {}

		////////////////////////////////////////////////////////////
		T operator()() {
			constuct();
			return this->st->at<T>(-1);
		}
	};

	template<>
	class Function<void(void)> : public BaseFunction  {
	public:
		////////////////////////////////////////////////////////////
		Function() {}

		////////////////////////////////////////////////////////////
		void operator()() {
			constuct();
		}
	};

}