#include "self_int_stack.h"

struct stack* init_stack(const unsigned prefer_size)
{
	struct stack* temp = malloc((2 + prefer_size) * sizeof(int));
	temp->size = prefer_size;
	temp->p = malloc(prefer_size * sizeof(int));
	temp->cnt = 0;
	return temp;
}

char* is_empty(const struct stack* current_stack)
{
	return (current_stack->cnt == 0) ? "The stack is empty!" : "The stack is not empty!";
}

void push(struct stack* current_stack,const int value)
{
	if (current_stack->cnt == current_stack->size)
	{
		current_stack->size = current_stack->size * 2;
		current_stack->p = realloc(current_stack->p, current_stack->size * sizeof(int));
	}
	*(current_stack->p + current_stack->cnt) = value;
	current_stack->cnt++;
}

int pop(struct stack* current_stack)
{
	if (!current_stack->cnt)
	{
		printf("The stack is empty, cannot pop it.\n");
		return -1;
	}
	int temp = *(current_stack->p + current_stack->cnt - 1);
	current_stack->cnt--;
	return temp;
}

int get_len(const struct stack* current_stack)
{
	return current_stack->cnt;
}

void clear_stack(struct stack* current_stack)
{
	free(current_stack);
}

int peak(const struct stack* current_stack) {
	if (current_stack->cnt == 0) {
		printf("The current stack is empty, cannot operate"
			" the peak operation.\n");
		return -1;
	}
	return *(current_stack->p + current_stack->cnt -1);
}