#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 *
 * @tree: is a pointer to the root node of the tree
 * to measure the size.
 * Return: 0 if the function is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size_l = 0;
	int size_r = 0;
	int tot_size = 0;

	if (tree == NULL)
		return (0);

	size_l = binary_tree_size(tree->left);
	size_r = binary_tree_size(tree->right);

	tot_size = size_l + size_r;
	return (1 + tot_size);
}
