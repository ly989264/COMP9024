#include "self_general_stack.h"

/*
struct stack {
	int size;
	int cnt;
	int typeCode;
	void* data;
};
*/

struct stack* initStack(const char* typeName) {
	// The initial size of the stack is 10
	// Acceptable type name is: int char double
	int type_code=0;//char:1, int:4, double:8
	if (strcmp(typeName, "int") == 0) {
		type_code = 4;
		struct stack *p = malloc(3 * sizeof(int) + 10 * sizeof(int));
		int* x = malloc(10 * sizeof(int));
	}
	else {
		if (strcmp(typeName, "char") == 0) {
			type_code = 1;
			struct stack *p = malloc(3 * sizeof(int) + 10 * sizeof(char));
			char* x = malloc(10 * sizeof(char));
		}
		else {
			if (strcmp(typeName, "double")==0) {
				type_code = 8;
				struct stack *p = malloc(3 * sizeof(int) + 10 * sizeof(double));
				double* x = malloc(10 * sizeof(double));
			}
			else {
				printf("The type input is not valid.\n");
				return NULL;
			}
		}
	}
	p->size = 10;
	p->cnt = 0;
	p->typeCode = type_code;
	p->data = (void*)x;
	return p;
}

int* voidPointer_to_intPointer(void* current_pointer) {}