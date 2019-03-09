#include "self_binary_tree_adt.h"

struct binary_node* create_binary_node(int value)
{
	struct binary_node* temp = (struct binary_node*)malloc(sizeof(struct binary_node));
	temp->value = value;
	temp->left_node = NULL;
	temp->right_node = NULL;
	return temp;
}

struct binary_tree* create_binary_tree()
{
	struct binary_tree* temp = (struct binary_tree*)malloc(sizeof(struct binary_tree));
	temp->root = NULL;
	return temp;
}

int is_binary_tree_empty(const struct binary_tree* current_tree)
{
	return (current_tree->root == NULL);
}

void add_node(struct binary_node* current_node, const int value)
{
	struct binary_node* new_node = create_binary_node(value);
	if (value<current_node->value)
	{
		if (current_node->left_node)
			add_node(current_node->left_node, value);
		else
		{
			current_node->left_node = new_node;
		}
	}
	else
	{
		if (current_node->right_node)
			add_node(current_node->right_node, value);
		else
			current_node->right_node = new_node;
	}
}

void add_binary_node(struct binary_tree* current_tree, const int value)
{
	if(is_binary_tree_empty(current_tree))
	{
		struct binary_node* temp = create_binary_node(value);
		current_tree->root = temp;
		return;
	}
	add_node(current_tree->root, value);
}

void traverse_testing(const struct binary_node* current_node)
{
	if (!current_node) return;
	if (current_node->left_node) printf("%d->%d\n", current_node->value, current_node->left_node->value);
	if (current_node->right_node) printf("%d->%d\n", current_node->value, current_node->right_node->value);
	traverse_testing(current_node->left_node);
	traverse_testing(current_node->right_node);	
}

int get_size_component(const struct binary_node* current_node, int *current_size)
{
	if (!current_node) return;
	(*current_size)++;
	get_size_component(current_node->left_node, current_size);
	get_size_component(current_node->right_node, current_size);
}

int get_size(const struct binary_tree* current_tree)
{
	int cnt = 0;
	get_size_component(current_tree->root, &cnt);
	return cnt;
}

int check_existence_component(const struct binary_node* current_node, const int value)
{
	if (!current_node)
		return 0;
	return (current_node->value == value || check_existence_component(current_node->left_node, value) || check_existence_component(current_node->right_node, value));
}

int check_existence(const struct binary_tree* current_tree, const int value)
{
	return check_existence_component(current_tree->root, value);
}

void quick_check_component(const struct binary_node* current_node, const int value, int* flag)
{
	if (!current_node)
		return;
	if (current_node->value == value)
	{
		*flag = 1;
		return;
	}
	if (current_node->value < value)
		quick_check_component(current_node->right_node, value, flag);
	else
		quick_check_component(current_node->left_node, value, flag);
	return;
}

int quick_check_existence(const struct binary_tree* current_tree, const int value)
{
	int flag = 0;
	quick_check_component(current_tree->root, value, &flag);
	if (flag) return 1;
	else return 0;
}

void print_binary_nodes(const struct binary_node* current_node, int cnt)
{
	if (!current_node)
	{
		printf("\n");
		return;
	}
	if (current_node->left_node)
	{
		print_binary_nodes(current_node->left_node, cnt + 2);
		for (int i = 0; i < cnt + 1; i++)
			printf(" ");
		printf("/\n");
	}
	for (int i = 0; i < cnt; i++)
		printf(" ");
	printf("%d\n", current_node->value);
	if (current_node->right_node)
	{
		for (int i = 0; i < cnt + 1; i++)
			printf(" ");
		printf("\\\n");
		print_binary_nodes(current_node->right_node, cnt + 2);
	}
	
}

void print_binary_tree(const struct binary_tree* current_tree)
{
	print_binary_nodes(current_tree->root, 0);
}

struct binary_node* delete_two_children_node(struct binary_node* current_node, struct binary_node* parent_node, int le)
{
	struct binary_node* new_node = current_node->left_node;
	struct binary_node* temp_parent = parent_node;
	int flag = 0;
	while(new_node->right_node)
	{
		temp_parent = new_node;
		new_node = new_node->right_node;
		flag++;
	}
	struct binary_node* new_leader = new_node;
	if (flag)
	{
		temp_parent->right_node = NULL;
		new_leader->right_node = current_node->right_node;
		new_leader->left_node = current_node->left_node;
	}
	else
	{
		new_leader->right_node = current_node->right_node;
	}
	free(current_node);
	if (parent_node)
	{
		if (le)
			parent_node->left_node = new_leader;
		else
			parent_node->right_node = new_leader;
	}
	return new_leader;
}



struct binary_node* delete_one_child_node(struct binary_node* current_node, struct binary_node* parent_node, int le)
{
	struct binary_node* new_node;
	if (current_node->left_node)
		new_node = current_node->left_node;
	else
		new_node = current_node->right_node;
	if(parent_node)
	{
		if(le)
		{
			parent_node->left_node = new_node;
		}
		else
		{
			parent_node->right_node = new_node;
		}
	}
	free(current_node);
	return new_node;
}

void delete_binary_node(struct binary_tree* current_tree, const int value)
{
	if (!current_tree->root)
	{
		printf("The binary tree is empty, cannot delete element from it.\n");
		return;
	}
	struct binary_node* current_node = current_tree->root;
	struct binary_node* current_parent = NULL;
	while(current_node)
	{
		if (current_node->value == value)
			break;
		if (current_node->value < value)
		{
			current_parent = current_node;
			current_node = current_node->right_node;
		}
		else
		{
			current_parent = current_node;
			current_node = current_node->left_node;
		}
	}
	if (!current_node)
	{
		printf("Cannot find the value in this binary tree.\n What are you thinking about?\n");
		return;
	}
	if(!current_parent)
	{
		if (current_node->left_node && current_node->right_node)
		{
			current_tree->root  =  delete_two_children_node(current_node, NULL, 0);
		}
		else
		{
			if(!current_node->left_node && !current_node->right_node)
			{
				free(current_node);
				current_tree->root = NULL;
			}
			else
			{
				current_tree->root = delete_one_child_node(current_node, NULL, 0);
			}
		}
	}
	else
	{
		if (current_node->left_node && current_node->right_node)
		{
			if (current_node == current_parent->left_node)
			{
				delete_two_children_node(current_node, current_parent, 1);
			}
			else
			{
				delete_two_children_node(current_node, current_parent, 0);
			}
		}
		else
		{
			if (!current_node->left_node && !current_node->right_node)
			{
				if (current_node == current_parent->left_node)
					current_parent->left_node = NULL;
				else
					current_parent->right_node = NULL;
				free(current_node);
			}
			else
			{
				if (current_node == current_parent->left_node)
					delete_one_child_node(current_node, current_parent, 1);
				else
					delete_one_child_node(current_node, current_parent, 0);
			}
		}
	}
}

void free_all_nodes(struct binary_node* current_node)
{
	if (!current_node)
		return;
	free_all_nodes(current_node->left_node);
	free_all_nodes(current_node->right_node);
	return;
}

void free_binary_tree(struct binary_tree* current_tree)
{
	if(!current_tree->root)
	{
		free(current_tree);
		return;
	}
	free_all_nodes(current_tree->root);
	free(current_tree);
	return;
}
