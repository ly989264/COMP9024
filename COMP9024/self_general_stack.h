#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	int size;
	int cnt;
	int typeCode;
	void* p;
};

struct stack* initStack(const char* typeName);