#include "binary_trees.h"

/**
 * max - helper function that returns max value of 2 ints
 * @x: int 1
 * @y: int 2
 * Return: maximum between 2 values
 */

int max(int x, int y)
{

	return ((x >= y) ? x : y);
}

/**
 * height - returns height of a node
 * @tree: binary_tree_t node to search
 * Return: Height as an int, 0 if NULL
 */

int height(binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl2 - function that returns whether a tree is AVL
 * assuming the first root passed from main is not NULL
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is aVL, 0 otherwise
 */

int binary_tree_is_avl2(const binary_tree_t *tree)
{
	int LH, RH;

	if (tree == NULL)
		return (1);

	LH = height(tree->left);

	RH = height(tree->right);

	if (abs(LH - RH) <= 1 && binary_tree_is_avl2(tree->left) != 0 &&
	    binary_tree_is_avl2(tree->right) != 0
	    && binary_tree_is_bst(tree) != 0)
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - function that returns whether a tree is AVL
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is aVL, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl2(tree));
}
