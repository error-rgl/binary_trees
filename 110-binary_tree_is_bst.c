#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if tree is binary search tree.
 *
 * @tree: pointer to the root node of the tree.
 * Return: 1 if valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_recursive((binary_tree_t *)tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_recursive - recursively checks if valid binary search tree.
 *
 * @tree: tree to check.
 * @min: minimum value root node must be greater than.
 * @max: maximum value root node must be less than.
 * Return: 1 if succesful, 0 if failed.
 */
int is_bst_recursive(binary_tree_t *tree, int min, int max)
{
	int my_min = min, my_max = max;
	int left = 0, right = 0;

	if (tree == NULL)
		return (1);
	if (tree->n == min || tree->n == max)
		return (0);
	if (tree->left)
		my_min = tree->left->n;
	if (tree->right)
		my_max = tree->right->n;
	if (tree->n <= my_min || tree->n >= my_max)
		return (0);
	if (my_min == min && my_max == max)
		return (1);
	left = is_bst_recursive(tree->left, min, tree->n);
	right = is_bst_recursive(tree->right, tree->n, max);
	return (left * right);
}
