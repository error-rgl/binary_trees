#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 *
 * @tree: is a pointer to the root node of the tree to count
 * the number of leaves.
 * Return: 0 if the tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaves_r = 0;
	int leaves_l = 0;
	int leaves;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	leaves_l = binary_tree_leaves(tree->left);
	leaves_r = binary_tree_leaves(tree->right);

	leaves = leaves_l + leaves_r;

	return (leaves);
}
