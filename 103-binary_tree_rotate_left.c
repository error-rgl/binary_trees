#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 *
 * @tree: pointer to the root node of the tree.
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *nw_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	/* Variable to hold child , becomes the new root*/
	nw_root = tree->right;
	/* Sets new_root parent to NULL*/
	nw_root->parent = tree->parent;
	tree->parent = nw_root;
	tree->right = nw_root->left;
	/* NULL check for tree->right*/
	if (tree->right)
		tree->right->parent = tree;
	nw_root->left = tree;
	return (tree->parent);
}
