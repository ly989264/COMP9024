#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define INITSIZE 10
#define SELF_INT_QUEUE

struct queue
{
	int size;//the size of the allocated space
	int base;//the index (just call it index) of the last element in the allocated space
	int num;//the number of elements in the allocated space
	int *data;
};

struct queue* initQueue();
int isQueueEmpty(const struct queue* current_queue);
char* isQueueEmptyVi(const struct queue* current_queue);
int lenQueue(const struct queue* current_queue);
void expand(struct queue* current_queue);
void enqueue(struct queue* current_queue, const int value);
int dequeue(struct queue* current_queue);
int peek(const struct queue* current_queue);
void clearQueue(struct queue* current_queue);
