#include "problem_set_queue.h"

static struct p_queue queueObject;

void p_queueInit()
{
	queueObject.num = 0;
	queueObject.base = 0;
	return;
}

int p_isEmpty()
{
	return (queueObject.num == 0);
}

void p_enqueue(int value)
{
	if (queueObject.num>=MAXQUEUEITEM)
	{
		printf("The queue is full, cannot enqueue any element.\n");
		return;
	}
	int position = (queueObject.base + queueObject.num) % MAXQUEUEITEM;
	queueObject.data[position] = value;
	queueObject.num++;
	return;
}

int p_dequeue()
{
	if (queueObject.num<=0)
	{
		printf("The queue is empty, cannot dequeue from it.\n");
		return -1;
	}
	queueObject.num--;
	int temp = queueObject.data[queueObject.base];
	queueObject.base = (queueObject.base+1)%MAXQUEUEITEM;
	return temp;
}


