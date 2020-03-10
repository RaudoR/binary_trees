#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;
	depth = binary_tree_left_max_depth(tree);
	return (tree_is_perfect_help(tree, depth, 0));
}

int tree_is_perfect_help(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (depth == level + 1);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (tree_is_perfect_help(tree->left, depth, level + 1) &&
		tree_is_perfect_help(tree->right, depth, level + 1));
}

int binary_tree_left_max_depth(const binary_tree_t *tree)
{
	int depth = 0;
	
	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

