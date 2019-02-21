#include "self_general_stack.h"

/*
struct stack {
	int size;
	int cnt;
	int typeCode;
	void* data;
};
*/

int configure_type(const char* typeName)
{
	if (strcmp(typeName, "int") == 0) {
		return 4;
	}
	else {
		if (strcmp(typeName, "char") == 0) {
			return 1;
		}
		else {
			if (strcmp(typeName, "double") == 0) {
				return 8;
			}
			else {
				return 0;
			}
		}
	}
}

struct stack* initStack(const char* typeName) {
	int type_code = configure_type(typeName);
	struct stack *p = malloc(3 * sizeof(int32_t) + 10 * type_code);//I use char, int32_t, and double
	p->size = 10;
	p->cnt = 0;
	p->typeCode = type_code;
	void* x = malloc(p->size * type_code);
	p->data = x;
	return p;
}

void expand_stack_size(struct stack* current_stack)
{
	if (current_stack->size == current_stack->cnt)
	{
		current_stack->size *= 2;
		current_stack->data = realloc(current_stack->data, current_stack->size*current_stack->typeCode);
	}
	return;
}

void gpush_char(struct stack* current_stack, const char value)
{
	if (current_stack->typeCode != 1)
	{
		printf("The type of the variable to be pushed into the stack does not match the stack type.\n");
		return;
	}
	expand_stack_size(current_stack);
	char *temp = (char*)current_stack->data;
	*(temp + current_stack->cnt) = value;//i think this will change the block the void* points
	current_stack->cnt++;
	return;
}

void gpush_int(struct stack* current_stack, const int32_t value)
{
	if (current_stack->typeCode != 4)
	{
		printf("The type of the variable to be pushed into the stack does not match the stack type.\n");
		return;
	}
	expand_stack_size(current_stack);
	int32_t *temp = (int32_t*)current_stack->data;
	*(temp + current_stack->cnt) = value;//i think this will change the block the void* points
	current_stack->cnt++;
	return;
}

void gpush_double(struct stack* current_stack, const double value)
{
	if (current_stack->typeCode != 8)
	{
		printf("The type of the variable to be pushed into the stack does not match the stack type.\n");
		return;
	}
	expand_stack_size(current_stack);
	double *temp = (double*)current_stack->data;
	*(temp + current_stack->cnt) = value;//i think this will change the block the void* points
	current_stack->cnt++;
	return;
}

char gpeak_char(const struct stack* current_stack)
{
	if (current_stack->cnt == 0)
	{
		printf("The stack is empty, cannot peak from this stack.\n");
		return '\0';
	}
	return *((char*)current_stack->data + current_stack->cnt - 1);
}

int32_t gpeak_int(const struct stack* current_stack)
{
	if (current_stack->cnt == 0)
	{
		printf("The stack is empty, cannot peak from this stack.\n");
		return '\0';
	}
	return *((int32_t*)current_stack->data + current_stack->cnt - 1);
}

double gpeak_double(const struct stack* current_stack)
{
	if (current_stack->cnt == 0)
	{
		printf("The stack is empty, cannot peak from this stack.\n");
		return '\0';
	}
	return *((double*)current_stack->data + current_stack->cnt - 1);
}


int get_length(const struct stack* current_stack)
{
	return current_stack->cnt;
}

char gpop_char(struct stack* current_stack)
{
	if (!current_stack->cnt)
	{
		printf("The stack is empty, cannot pop from this stack.\n");
		return '\0';
	}
	char temp = *((char*)current_stack->data + current_stack->cnt - 1);
	current_stack->cnt--;
	return temp;
}

int32_t gpop_int(struct stack* current_stack)
{
	if (!current_stack->cnt)
	{
		printf("The stack is empty, cannot pop from this stack.\n");
		return '\0';
	}
	int32_t temp = *((int32_t*)current_stack->data + current_stack->cnt - 1);
	current_stack->cnt--;
	return temp;
}

double gpop_double(struct stack* current_stack)
{
	if (!current_stack->cnt)
	{
		printf("The stack is empty, cannot pop from this stack.\n");
		return '\0';
	}
	double temp = *((double*)current_stack->data + current_stack->cnt - 1);
	current_stack->cnt--;
	return temp;
}

char* gis_empty(const struct stack* current_stack)
{
	return (!current_stack->cnt) ? "The stack is empty." : "The stack is not empty.";
}

void gprint_stack(const struct stack* current_stack)
{
	if(!current_stack->cnt)
	{
		printf("\n");
		return;
	}
	for (int i=0;i<current_stack->cnt;i++)
	{
		switch (current_stack->typeCode)
		{
		case 1:
			printf("%c ", *((char*)current_stack->data + i));
			break;
		case 4:
			printf("%d ", *((int*)current_stack->data + i));
			break;
		default:
			printf("%f ", *((double*)current_stack->data + i));
			break;
		}
	}
	printf("\n");
	return;
}

void gdelete_stack(struct stack* current_stack)
{
	free(current_stack);
}