#pragma once
#include "stdio.h"
#include "stdlib.h"

struct tree_node
{
	int value;
	int child_size;
	struct tree_node** child_p;
};

struct tree
{
	struct tree_node* root;
};

struct tree_node* create_new_tree_node(int value);
struct tree* create_new_tree();
void attach_tree(struct tree_node* target_node, const struct tree* new_tree);
void print_tree_component(const struct tree_node* current_node, int n);
void print_tree(const struct tree* current_tree);
void tree_preorder_component(const struct tree_node* current_node);
void tree_preorder_traverse(const struct tree* current_tree);
void tree_postorder_component(const struct tree_node* current_node);
void tree_postorder_traverse(const struct tree* current_tree);
void let_tree_node_fly(struct tree_node* current_node);
void let_tree_free(struct tree* current_tree);
void testing();