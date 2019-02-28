#pragma once
#include <stdio.h>
#include <stdlib.h>
#define SELF_SINGLE_LINKED_LIST

struct node
{
	int value;
	struct node* next;
};

struct node* create_linked_list(const int value);
void insert_node(struct node* current_ll, const int value);
struct node* delete_last_node(struct node* current_ll);
struct node* delete_node(struct node* current_ll, const int value);
void show_linked_list(const struct node* current_ll);
struct node* search_value(const struct node* current_ll, const int value);
void free_linked_list(struct node* current_ll);