#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 *
 * @tree: pointer to the root node of the tree.
 * Return: 1 if perfect, or 0 if NULL or not perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int check = 0;

	if (tree == NULL)
		return (0);

	if (binary_tree_balance(tree))
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	check = binary_tree_is_perfect(tree->left) * binary_tree_is_perfect(tree->right);
	return (check);
}

/**
 * binary_tree_balance - measures the balance factor of binary tree
 * balance factor is difference in height of two children's subtrees.
 *
 * @tree: pointer to the root node of the tree.
 * Return: balance factor, or 0 if NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height_helper(tree->left) - height_helper(tree->right));
}

/* using height_helper, not height func, to include root's child in balance */

/**
 * height_helper - the heavy lifter.
 *
 * @tree: tree to measure.
 * Return: height, root inclusive.
 */
size_t height_helper(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = (1 + height_helper(tree->left));
	right = (1 + height_helper(tree->right));

	if (left > right)
		return (left);

	return (right);
}

/**
 * binary_tree_is_leaf - checks if the given node is a leaf (no children).
 *
 * @node: pointer to the binary tree node to check if leaf.
 * Return: 1 if node is a leaf, 0 if not.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->right || node->left)
		return (0);
	return (1);
}
