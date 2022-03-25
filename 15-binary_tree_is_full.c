#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 *
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 0 if the tree is NULL or is not full, 1 if it is full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	/*If I don't exist*/
	if (tree == NULL)
		return (0);

	 /*If I have no child*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If I have only a right */
	if (tree->left != NULL && tree->right == NULL)
		return (0);

	/* If I have only a left */
	if (tree->left == NULL && tree->right != NULL)
		return (0);

	/*Else, I have two childs*/
	/*Check  both childs fulliness*/
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	/*If both are full, I am full too*/
	if (left == 1 && right == 1)
		return (1);

	return (0);
}
