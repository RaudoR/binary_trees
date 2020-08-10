#include "binary_trees.h"
/*
https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec04.pdf
http://www.crazyforcode.com/heap-data-structure/
*/

char *convert(unsigned long int num, int base)
{
	static char *rep;
	static char buffer[33];
	char *ptr;

	rep = "0123456789";
	ptr = &buffer[32];
	*ptr=0;
	do{
		*--ptr=rep[num%base];
		num/=base;
	   }while(num);

	return(ptr);
}

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of tree of type size_t, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	++size;

	return (size);
}

void heapify(heap_t *node, int value)
{
	heap_t *temp;

	temp = node;

	if (temp->parent == NULL)
		return;

	if (node->n > node->parent->n)
	{
		node->n =  node->parent->n;
		node->parent->n = value;
		temp = node->parent;
	
		heapify(temp, value);
	}

	else
		return;
}


heap_t *heap_insert(heap_t **root, int value)
{
	char *ptr;
	heap_t *temp;
	unsigned long int i;
	size_t size;
	if (root == NULL || *root == NULL)
	{
		*root = (binary_tree_node(NULL, value));
		return *root;
	}

	temp = *root;
	size =  binary_tree_size(temp) + 1;

		ptr = convert(size, 2);

	for (i = 1; i < strlen(ptr) -1; ++i)
	{
		if (ptr[i] == '1')
			temp = temp->right;

		else
			temp = temp->left;
	}

	if (ptr[i] == '1')
	{
		temp->right = binary_tree_node(temp, value);
		heapify(temp->right, value);
		return temp->right;
	}
	else
	{
		temp->left =  binary_tree_node(temp, value);
		heapify(temp->left, value);
		return temp->left;
	}
}
