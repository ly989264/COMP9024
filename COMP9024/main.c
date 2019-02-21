// #include "self_int_stack.h"
#include "self_general_stack.h"


int main()
{
#ifdef SELF_INT_STACK
	struct stack* g = init_stack(5);
	printf("%s\n", is_empty(g));
	push(g, 1);
	push(g, 2);
	push(g, 4);
	printf("%s\n", is_empty(g));
	printf("The length of the stack is: %d.\n", get_len(g));
	printf("%d\n", pop(g));
	printf("Now the length of the stack is %d.\n", get_len(g));
	printf("The current peak element is: %d\n", peak(g));
	clear_stack(g);
#endif
#ifdef SELF_GENERAL_STACK
	struct stack* x = initStack("int");
	printf("%s\n", gis_empty(x));
	gpush_int(x, 1);
	gprint_stack(x);
	gpush_int(x, 0);
	gprint_stack(x);
	gpush_int(x, 0);
	gprint_stack(x);
	gpop_int(x);
	gprint_stack(x);
	printf("The length of the stack is %d.\n", get_length(x));
	printf("%s\n", gis_empty(x));
	gdelete_stack(x);
#endif
	system("pause");
	return 0;
}