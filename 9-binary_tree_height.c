#include "binary_trees.h"
/**
 * binary_tree_height - determine the height of the tree
 * @tree: tree of nodes
 * Return: height of tree or NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);

	if (lheight < rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}
