#include "binary_trees.h"
void bt_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * bt_levelorder - goes through a binary tree using
 * level-order traversal.
 *
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: is a pointer to a function to call for each node.
 */
void bt_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);

	bt_levelorder(tree->left, func);
	bt_levelorder(tree->right, func);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal.
 *
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: is a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	bt_levelorder(tree, func);
}
