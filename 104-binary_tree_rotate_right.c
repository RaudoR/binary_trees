#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation on a
 * binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = tree->left;

	tree->left  = temp->right;

	if (tree->right != NULL)
		temp->right->parent = tree;

	temp->right = tree;

	tree->parent = temp;

	return (temp);
}
