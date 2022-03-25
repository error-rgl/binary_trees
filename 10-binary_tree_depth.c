#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *
 * @tree: is a pointer to the node to measure the depth.
 * Return: If tree is NULL, the function return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}
