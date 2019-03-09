#include <stdio.h>
#include <stdlib.h>
// #include "self_int_stack.h"
// #include "self_general_stack.h"
// #include "lecture_stack.h"
// #include "problem_set_queue.h"
// #include "self_int_queue.h"
// #include "self_single_linked_list.h"
// #include "self_tree.h"
#include "self_binary_tree_adt.h"


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
#ifdef SELF_SINGLE_LINKED_LIST
	/*
	 *	testing these functions:
	 *	struct node* create_linked_list(const int value);
	 *	void insert_node(struct node* current_ll, const int value);
	 *	struct node* delete_last_node(struct node* current_ll);
	 *	struct node* delete_node(struct node* current_ll, const int value);
	 *	void show_linked_list(const struct node* current_ll);
	 *	struct node* search_value(const struct node* current_ll, const int value);
	 *	void free_linked_list(struct node* current_ll);
	 */
	struct node* linked_list = create_linked_list(10);
	insert_node(linked_list, 15);
	insert_node(linked_list, 20);
	insert_node(linked_list, 10);
	insert_node(linked_list, 25);
	insert_node(linked_list, 30);
	insert_node(linked_list, 35);
	insert_node(linked_list, 40);
	show_linked_list(linked_list);
	linked_list = delete_last_node(linked_list);
	show_linked_list(linked_list);
	linked_list = delete_last_node(linked_list);
	show_linked_list(linked_list);
	linked_list = delete_node(linked_list, 10);
	show_linked_list(linked_list);
	struct node* t20 = search_value(linked_list, 20);
	printf("%d\n", t20->value);
	show_linked_list(t20);
	free_linked_list(linked_list);
#endif
	struct binary_tree* x = create_binary_tree();
	// printf("%d\n", is_binary_tree_empty(x));
	add_binary_node(x, 5);
	// printf("%d\n", is_binary_tree_empty(x));
	add_binary_node(x, 3);
	add_binary_node(x, 8);
	add_binary_node(x, 6);
	add_binary_node(x, 7);
	add_binary_node(x, 9);
	traverse_testing(x->root);
	printf("%d\n", get_size(x));
	printf("%d\n", check_existence(x, 1));
	printf("%d\n", check_existence(x, 5));
	printf("%d\n", check_existence(x, 2));
	printf("%d\n", check_existence(x, 6));
	printf("%d\n", quick_check_existence(x, 1));
	printf("%d\n", quick_check_existence(x, 5));
	printf("%d\n", quick_check_existence(x, 2));
	printf("%d\n", quick_check_existence(x, 6));
	printf("\n");
	print_binary_tree(x);
	printf("\n");
	delete_binary_node(x, 5);
	traverse_testing(x->root);
	printf("\n");
	print_binary_tree(x);
	free_binary_tree(x);
	system("pause");
	return 0;
}