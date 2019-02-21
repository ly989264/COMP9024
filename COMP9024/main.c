#include "stack.h"

int main()
{
	struct stack* x = init_stack(5);
	printf("%s\n", is_empty(x));
	push(x, 1);
	push(x, 2);
	push(x, 4);
	printf("%s\n", is_empty(x));
	printf("The length of the stack is: %d.\n", get_len(x));
	printf("%d\n", pop(x));
	printf("Now the length of the stack is %d.\n", get_len(x));
	clear_stack(x);
	return 0;
}