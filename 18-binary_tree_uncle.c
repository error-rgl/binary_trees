#include "binary_trees.h"

/**
 * binary_tree_uncle - finds node's aunt or uncle.
 *
 * @node: pointer to the node of the binary tree.
 * Return: pointer to location of parent's sibling.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *p, *gp;

	if (node == NULL || binary_tree_is_root(node))
		return (NULL);
	p = node->parent;
	if (binary_tree_is_root(p))
		return (NULL);
	gp = p->parent;
	if (two_children(gp))
	{
		if (gp->left == p)
			return (gp->right);
		return (gp->left);
	}
	return (NULL);
}

/**
 * binary_tree_is_root - checks if the given node is a root (no parent).
 * @node: pointer to the binary tree node to check if root.
 * Return: 1 if node is a root, 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent)
		return (0);
	return (1);
}


/**
 * two_children - checks if node has two children.
 *
 * @tree: pointer to the root node of the tree.
 * Return: 1 if there are 2 children, 0 otherwise.
 */
size_t two_children(const binary_tree_t *tree)
{
	if (tree->left && tree->right)
		return (1);

	return (0);
}
