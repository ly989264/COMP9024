#include "self_int_queue.h"

// struct queue
// {
// 	int size;//the size of the allocated space
// 	int base;//the index (just call it index) of the last element in the allocated space
// 	int num;//the number of elements in the allocated space
// 	int *data;
// };

struct queue* initQueue()
{
	struct queue* x = malloc((3 + INITSIZE) * sizeof(int));
	x->size = INITSIZE;
	x->base = 0;
	x->num = 0;
	int* p = malloc(INITSIZE * sizeof(int));
	x->data = p;
	return x;
}

int isQueueEmpty(const struct queue* current_queue)
{
	return (current_queue->num == 0);//return 1 if empty, 0 otherwise
}

char* isQueueEmptyVi(const struct queue* current_queue)
{
	return (current_queue->num == 0) ? "This queue is empty." : "This queue is not empty";
}

int lenQueue(const struct queue* current_queue)
{
	return current_queue->num;
}

void expand(struct queue* current_queue)
{
	const int previous_size = current_queue->size;
	current_queue->size *= 2;
	current_queue->data = realloc(current_queue->data, current_queue->size * sizeof(int));
	if (current_queue->base + current_queue->num>previous_size)
	{
		for (int i = 0;i<(current_queue->base+current_queue->num-previous_size);i++)
		{
			*(current_queue->data + i + previous_size) = *(current_queue->data + i);
		}
	}
	return;
}

void enqueue(struct queue* current_queue, const int value)
{
	if (current_queue->num == current_queue->size)
	{
		expand(current_queue);
	}
	*(current_queue->data + current_queue->base + current_queue->num) = value;
	current_queue->num++;
	return;
}

int dequeue(struct queue* current_queue)
{
	assert(!isQueueEmpty(current_queue));
	int temp = *(current_queue->data + current_queue->base);
	current_queue->base = (current_queue->base + 1) % current_queue->size;
	current_queue->num--;
	return temp;
}

int peek(const struct queue* current_queue)
{
	assert(!isQueueEmpty(current_queue));
	return *(current_queue->data + current_queue->base);
}

void clearQueue(struct queue* current_queue)
{
	free(current_queue->data);
	free(current_queue);
	return;
}