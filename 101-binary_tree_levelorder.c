#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree,
 * level-order traversal
 *
 * @tree: pointer to the root node.
 * @func: pointer to a function to call for each node.
 * Return: no return.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, height;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (level = 1; level <= height + 1; level++)
		current_level(tree, level, func);
}

/**
 * current_level - calls func on current level of tree.
 *
 * @tree: pointer to the root node of the tree.
 * @level: level of the tree.
 * @func: pointer to function called at current level.
 * Return: no return.
 */
void current_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		current_level(tree->left, level - 1, func);
		current_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree.
 * Return: height of tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);

	height = height_helper(tree);
	return (height - 1);
}

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
