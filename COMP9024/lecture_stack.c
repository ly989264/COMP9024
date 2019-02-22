#include "lecture_stack.h"
#include "self_general_stack.h"

//The stack from the lecture use a static stack object, which means that there can only be one stack object, and if using l_stackInit
//function a second time, the already existing stack object will be clear to empty

static struct l_stack stackObject;

void l_stackInit()
{
	stackObject.top = -1;
}

int l_isEmpty()
{
	return (stackObject.top < 0);
}

void l_push(char ch)
{
	if (stackObject.top>=MAXITEMS-1)
	{
		printf("The stack is full, cannot push element into it.\n");
		return;
	}
	stackObject.item[++stackObject.top] = ch;
	return;
}

char l_pop()
{
	if (l_isEmpty())
	{
		printf("The stack is empty, cannot pop from it.\n");
		return '\0';
	}
	return stackObject.item[stackObject.top--];
}