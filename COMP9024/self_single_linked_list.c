#include "self_single_linked_list.h"

struct node* create_linked_list(const int value)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void insert_node(struct node* current_ll, const int value)
{
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->value = value;
	newnode->next = NULL;
	while(current_ll->next)
	{
		current_ll = current_ll->next;
	}
	current_ll->next = newnode;
	return;
}

struct node* delete_last_node(struct node* current_ll)
{
	if (!current_ll->next)
	{
		free(current_ll);
		return NULL;
	}
	struct node* base = current_ll;
	while (current_ll->next->next)
	{
		current_ll = current_ll->next;
	}
	struct node* temp = current_ll->next;
	current_ll->next = NULL;
	free(temp);
	return base;
}

struct node* delete_node(struct node* current_ll, const int value)
{
	if (current_ll->value == value)
	{
		if (!current_ll->next)
		{
			free(current_ll);
			return NULL;
		}
		else
		{
			struct node* temp = current_ll->next;
			free(current_ll);
			return delete_node(temp, value);
		}
	}
	if (!current_ll->next)
	{
		return current_ll;
	}
	struct node* base = current_ll;
	while (current_ll->next->next)
	{
		if (current_ll->next->value == value)
		{
			struct node* temp = current_ll->next;
			current_ll->next = temp->next;
			free(temp);
		}
		current_ll = current_ll->next;
	}
	if (current_ll->next->value == value)
	{
		struct node* temp = current_ll->next;
		current_ll->next = temp->next;
		free(temp);
	}
	return base;
}

void show_linked_list(const struct node* current_ll)
{
	while (current_ll->next)
	{
		printf("%d ", current_ll->value);
		current_ll = current_ll->next;
	}
	printf("%d\n", current_ll->value);
	return;
}

struct node* search_value(const struct node* current_ll, const int value)
{
	//return the first node that has the certain value value
	while (current_ll->next)
	{
		if (current_ll->value==value)
		{
			return current_ll;
		}
		current_ll = current_ll->next;
	}
	if (current_ll->value == value)
	{
		return current_ll;
	}
	return NULL;
}

void free_linked_list(struct node* current_ll)
{
	while(current_ll->next)
	{
		struct node* temp = current_ll;
		current_ll = current_ll->next;
		free(temp);
	}
	free(current_ll);
	return;
}


