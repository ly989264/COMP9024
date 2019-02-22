#pragma once
#define MAXITEMS 10
#define LECTURE_STACK

struct l_stack
{
	char item[MAXITEMS];
	int top;
};

void l_stackInit();
int l_isEmpty();
void l_push(char);
char l_pop();