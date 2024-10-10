#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_ALLOC_SIZE 2
#define DEFAULT_ALLOC_MULT 1.5

typedef unsigned long long size_t; 
typedef size_t poffset;
namespace nin {
	class State;
	typedef size_t(*runtime_function)(State*);
}