#include <stdio.h>
#include <stdlib.h>
// #include "self_int_stack.h"
// #include "self_general_stack.h"
// #include "lecture_stack.h"
// #include "problem_set_queue.h"
#include "self_int_queue.h"


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
#ifdef LECTURE_STACK
	l_stackInit();
	l_push('a');
	l_push('b');
	printf("%c\n", l_pop());
	printf("%s\n", (l_isEmpty() == 1) ? "The stack is empty." : "The stack is not empty.");
	l_stackInit();
	printf("%s\n", (l_isEmpty() == 1) ? "The stack is empty." : "The stack is not empty.");
#endif
#ifdef PROBLEM_SET_QUEUE
	p_queueInit();
	p_enqueue(1);
	p_enqueue(2);
	p_enqueue(3);
	p_enqueue(4);
	p_enqueue(5);
	p_enqueue(6);
	p_enqueue(7);
	p_enqueue(8);
	printf("%s\n", (p_isEmpty()) ? "The queue is empty." : "The queue is not empty.");
	printf("%d\n",p_dequeue());
	printf("%d\n", p_dequeue());
	p_enqueue(9);
	p_enqueue(10);
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%d\n", p_dequeue());
	printf("%s\n", (p_isEmpty()) ? "The queue is empty." : "The queue is not empty.");
#endif
#ifdef SELF_INT_QUEUE
	struct queue* x = initQueue();
	printf("%s\n", isQueueEmptyVi(x));
	enqueue(x, 1);
	enqueue(x, 2);
	enqueue(x, 3);
	printf("Now: %s\n", isQueueEmptyVi(x));
	enqueue(x, 1);
	enqueue(x, 2);
	enqueue(x, 3);
	enqueue(x, 1);
	enqueue(x, 2);
	enqueue(x, 3);
	enqueue(x, 1);
	enqueue(x, 2);
	enqueue(x, 3);
	printf("The length of this queue is %d.\n", lenQueue(x));
	printf("Now try dequeue: \n");
	printf("%d\n", dequeue(x));
	printf("%d\n", dequeue(x));
	printf("%d\n", dequeue(x));
	printf("%d\n", dequeue(x));
	printf("%d\n", dequeue(x));
	printf("%d\n", dequeue(x));
	printf("The length of this queue is %d.\n", lenQueue(x));
	printf("%s\n", isQueueEmptyVi(x));
	printf("%d\n", peek(x));
	printf("The length of this queue is %d.\n", lenQueue(x));
	clearQueue(x);
#endif
	system("pause");
	return 0;
}