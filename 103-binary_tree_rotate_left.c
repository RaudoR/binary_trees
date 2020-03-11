#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation on a binary
 * tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *temp = tree->right;

	tree->right = temp->left;

	if (temp->left != NULL)
		temp->left->parent = tree;

	temp->left = tree;

	tree->parent = temp;

	return (temp);

}
