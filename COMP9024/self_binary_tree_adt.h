#pragma once
#include "stdio.h"
#include "stdlib.h"

struct binary_node
{
	int value;
	struct binary_node* left_node;
	struct binary_node* right_node;
};

struct binary_tree
{
	struct binary_node* root;
};

struct binary_node* create_binary_node(int value);
struct binary_tree* create_binary_tree();
int is_binary_tree_empty(const struct binary_tree* current_tree);
void add_binary_node(struct binary_tree* current_tree, const int value);
void traverse_testing(const struct binary_node* current_node);
int get_size(const struct binary_tree* current_tree);
int check_existence(const struct binary_tree* current_tree, const int value);
int quick_check_existence(const struct binary_tree* current_tree, const int value);
void print_binary_tree(const struct binary_tree* current_tree);
void delete_binary_node(struct binary_tree* current_tree, const int value);
void free_binary_tree(struct binary_tree* current_tree);