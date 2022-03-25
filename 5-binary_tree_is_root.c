#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if the given node is a root (no parent).
 *
 * @node: pointer to the binary tree node to check if root.
 * Return: 1 if node is a root, 0 if not.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent)
		return (0);
	return (1);
}
