#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: the root node to check for completeness
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **bt_array;
	binary_tree_t *root;
	int max_depth, max_left, i;

	if (tree == NULL)
		return (1);
	/* Find overall max depth, and left max depth */
	max_depth = find_max_depth(tree);
	root = (binary_tree_t *)tree;
	for (max_left = 1; root->left; max_left++)
		root = root->left;
	if (max_depth != max_left)
		return (0);
	/* Create and fill array of row at max depth */
	bt_array = malloc(sizeof(binary_tree_t *) * 2 * max_left);
	if (bt_array == NULL)
		return (0);
	for (i = 0; i < 2 * max_left; i++)
		bt_array[i] = NULL;
	root = (binary_tree_t *)tree;
	comp_fill_array(bt_array, root, max_left);

	/* Check array for gaps */
	if (comp_gap_check(bt_array, 2 * max_left))
	{
		free(bt_array);
		return (0);
	}

	free(bt_array);
	return (1);
}

/**
 * find_max_depth - finds the max depth of a binary tree
 * @root: pointer to the root of the tree
 * Return: the max depth of the tree
 */
int find_max_depth(const binary_tree_t *root)
{
	int ldepth, rdepth;

	if (root == NULL)
		return (0);

	ldepth = find_max_depth(root->left);
	rdepth = find_max_depth(root->right);

	if (ldepth > rdepth)
		return (ldepth + 1);
	else
		return (rdepth + 1);
}

/**
 * comp_fill_array - fills an array with pointers to a row in a binary tree
 * @bt_array: the array to be filled
 * @root: the root of the tree
 * @depth: the depth of the row to fill the array with
 */
void comp_fill_array(binary_tree_t **bt_array, binary_tree_t *root, int depth)
{
	int target_row, current_row, index;

	index = 0;
	target_row = depth;
	current_row = 1;

	comp_fill_array_help(bt_array, root, target_row, current_row, &index);
}

/**
 * comp_fill_array_help - fills an array with pntrs to a row in a binary tree
 * @bt_array: the array to be filled
 * @node: the root of the tree
 * @target: the depth of the row to be copied
 * @depth: the current depth
 * @idx: the index of the array to fill
 */
void comp_fill_array_help(binary_tree_t **bt_array, binary_tree_t *node,
		int target, int depth, int *idx)
{
	if (node == NULL)
	{
		if (depth == target)
			(*idx)++;
		return;
	}
	if (depth == target)
	{
		bt_array[*idx] = node;
		(*idx)++;
	}

	comp_fill_array_help(bt_array, node->left, target, depth + 1, idx);
	comp_fill_array_help(bt_array, node->right, target, depth + 1, idx);
}

/**
 * comp_gap_check - checks an array for NULL gaps.
 * @bt_array: array of pointers
 * @size: the size of the array
 * Return: 0 if there are no gaps, 1 if there is a NotNull - NULL - NotNull gap
 */
int comp_gap_check(binary_tree_t **bt_array, int size)
{
	int i, flag;

	for (i = 0, flag = 0; i < size; i++)
	{
		if (bt_array[i] && flag)
			return (1);
		else if (bt_array[i] == NULL)
			flag = 1;
	}
	return (0);
}
