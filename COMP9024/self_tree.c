#include "self_tree.h"

// struct tree_node
// {
// 	int value;
// 	int child_size;
// struct tree_node** child_p;
// };
//
// struct tree
// {
// 	struct tree_node* root;
// };

struct tree_node* create_new_tree_node(int value)
{
	struct tree_node* temp = (struct tree_node*)malloc(sizeof(struct tree_node));
	temp->value = value;
	temp->child_size = 0;
	temp->child_p = NULL;
	return temp;
}

struct tree* create_new_tree()
{
	struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
	temp->root = NULL;
	return temp;
}

void attach_tree(struct tree_node* target_node, const struct tree* new_tree)
{
	if (!target_node->child_size)
	{
		target_node->child_size++;
		struct tree_node** x = (struct tree_node**)malloc(sizeof(struct tree_node*));
		*x = new_tree->root;
		target_node->child_p = x;
	}
	else
	{
		target_node->child_size++;
		struct tree_node** new_p = (struct tree_node**)malloc(target_node->child_size * sizeof(struct tree_node*));
		for (int i=0;i<target_node->child_size-1;i++)
		{
			*(new_p + i) = *(target_node->child_p + i);
		}
		*(new_p + target_node->child_size - 1) = new_tree->root;
		free(target_node->child_p);
		target_node->child_p = new_p;
	}
}

void attach_node(struct tree_node* target_node, const struct tree_node* new_node)
{
	if (!target_node->child_size)
	{
		target_node->child_size++;
		struct tree_node** temp = (struct tree_node**)malloc(sizeof(struct tree_node*));
		*temp = new_node;
		target_node->child_p = temp;
	}
	else
	{
		target_node->child_size++;
		struct tree_node** new_p = (struct tree_node**)malloc(target_node->child_size * sizeof(struct tree_node*));
		for (int i = 0; i < target_node->child_size - 1; i++)
		{
			*(new_p + i) = *(target_node->child_p + i);
		}
		*(new_p + target_node->child_size - 1) = new_node;
		free(target_node->child_p);
		target_node->child_p = new_p;
	}
}

void print_tree_component(const struct tree_node* current_node, int n)
{
	if(!current_node->child_size)
	{
		for (int i = 0; i < n; i++) printf(" ");
		printf("%d\n", current_node->value);
	}
	else
	{
		int length = current_node->child_size;
		int first_half_length = length / 2;
		int second_half_length = length - first_half_length;
		for (int i=0;i<first_half_length;i++)
			print_tree_component(*(current_node->child_p + i), n + 2);
		for (int i = 0; i < n; i++)
			printf(" ");
		printf("%d\n", current_node->value);
		for (int i = 0; i < second_half_length; i++)
			print_tree_component(*(current_node->child_p + first_half_length + i), n + 2);
	}
}

void print_tree(const struct tree* current_tree)
{
	if(!current_tree->root)
	{
		return;
	}
	print_tree_component(current_tree->root, 0);
}

void tree_preorder_component(const struct tree_node* current_node)
{
	printf("%d ", current_node->value);
	for (int i=0;i<current_node->child_size;i++)
	{
		tree_preorder_component(*(current_node->child_p + i));
	}
}

void tree_preorder_traverse(const struct tree* current_tree)
{
	if (!current_tree->root)
		return;
	tree_preorder_component(current_tree->root);
	printf("\n");
}

void tree_postorder_component(const struct tree_node* current_node)
{
	for (int i = 0; i < current_node->child_size; i++)
		tree_postorder_component(*(current_node->child_p + i));
	printf("%d ", current_node->value);
}

void tree_postorder_traverse(const struct tree* current_tree)
{
	if (!current_tree->root)
		return;
	tree_postorder_component(current_tree->root);
	printf("\n");
}

void let_tree_node_fly(struct tree_node* current_node)
{
	for (int i = 0; i < current_node->child_size; i++)
		let_tree_node_fly(*(current_node->child_p + i));
	free(current_node);
}

void let_tree_free(struct tree* current_tree)
{
	if (!current_tree->root)
	{
		free(current_tree);
		return;
	}
	let_tree_node_fly(current_tree->root);
	free(current_tree);
	return;
}


void testing()
{
	struct tree* a = create_new_tree();
	a->root = create_new_tree_node(1);
	struct tree_node* b2 = create_new_tree_node(2);
	struct tree_node* b3 = create_new_tree_node(3);
	attach_node(a->root, b2);
	attach_node(a->root, b3);
	attach_node(b2, create_new_tree_node(4));
	attach_node(b3, create_new_tree_node(5));
	struct tree_node* b6 = create_new_tree_node(6);
	attach_node(b3, b6);
	attach_node(b3, create_new_tree_node(7));
	attach_node(b6, create_new_tree_node(8));
	attach_node(b6, create_new_tree_node(9));
	
	for (int i=0;i<2;i++)
	{
		printf("%d ", (*(a->root->child_p + i))->value);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", (*(b3->child_p + i))->value);
	}
	printf("\n");
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", (*(b6->child_p + i))->value);
	}
	printf("\n\n");
	print_tree(a);
	tree_preorder_traverse(a);
	tree_postorder_traverse(a);
	let_tree_free(a);
}