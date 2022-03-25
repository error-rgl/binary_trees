#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 *
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: 0 if the tree is NULL and the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height_l = 0;
	int height_r = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	height_l = 1 + binary_tree_height(tree->left);
	height_r = 1 + binary_tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);

	else
		return (height_r);
}
