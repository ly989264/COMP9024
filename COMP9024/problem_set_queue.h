#pragma once
#include <stdio.h>
#define MAXQUEUEITEM 10
#define PROBLEM_SET_QUEUE

struct p_queue
{
	int data[MAXQUEUEITEM];
	int num;
	int base;
};

void p_queueInit();
int p_isEmpty();
void p_enqueue(int);
int p_dequeue();