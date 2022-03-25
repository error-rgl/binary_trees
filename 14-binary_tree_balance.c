#include "binary_trees.h"

/**
 * bt_height - measures the balance factor of binary tree
 * balance factor is difference in height of two children's subtrees.
 *
 * @tree: pointer to the root node of the tree
 * Return: balance factor, or 0 if NULL
 */
size_t bt_height(const binary_tree_t *tree)
{
	int height_l = 0;
	int height_r = 0;

	if (tree == NULL) /*I don't exist*/
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left) /*measure my left branch*/
		height_l = 1 + bt_height(tree->left);

	if (tree->right) /*measure my right branch*/
		height_r = 1 + bt_height(tree->right);

	if (height_l > height_r) /*the left is longer*/
		return (height_l);

	else /*the right is longer*/
		return (height_r);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 *
 * @tree: is a pointer to the root node of the tree to
 * measure the balance factor.
 * Return: 0 if the tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (0);

	balance_factor =  bt_height(tree->left) -  bt_height(tree->right);

	return (balance_factor);
}
