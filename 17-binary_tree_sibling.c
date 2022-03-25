#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 *
 * @node: pointer to the node to find the sibling.
 * Return: pointer to sibling node, or NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *tmp;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	tmp = node->parent;
	if  (two_children(tmp))
	{
		if (tmp->left == node)
			return (tmp->right);

		return (tmp->left);
	}
	return (NULL);
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
