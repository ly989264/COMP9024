#pragma once
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int size;
	//for int
	int *p;
	int cnt;
};

struct stack* init_stack(unsigned prefer_size);
char* is_empty(const struct stack* current_stack);
void push(struct stack* current_stack, const int value);
int pop(struct stack* current_stack);
int get_len(const struct stack* current_stack);
void clear_stack(struct stack* current_stack);