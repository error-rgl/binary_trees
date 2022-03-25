#include "binary_trees.h"

binary_tree_t *sa(binary_tree_t *a, binary_tree_t *b,
				   binary_tree_t *aa, binary_tree_t *bb, int level);

/**
 * sa - recursively search a coincidence in ancestors of same or
 * different level in a binary tree.
 *
 * @a : first node
 * @b : second node
 * @aa : a or ancestor of a
 * @bb : b or ancestor of b
 * @level: level of recursion
 * Return: the common ancestor if found, else, a NULL value
 */

binary_tree_t *sa(binary_tree_t *a, binary_tree_t *b,
				   binary_tree_t *aa, binary_tree_t *bb, int level)
{
	if (a == NULL || b == NULL || aa == NULL || bb == NULL)
		return (NULL);

	/*Check for same level common ancestor*/
	if (aa == bb)
		return (aa);
	/*Check for different level common ancestor*/
	if (a == bb)
		return (bb);
	if (b == aa)
		return (aa);

	/*Other kind of different ancestor*/
	if (level != 0)
	{
		if (bb->parent)
			if (aa == bb->parent)
				return (aa);

		if (aa->parent)
			if (bb == aa->parent)
				return (bb);
	}

	/*Check next level of ancestors*/
	return (sa(a, b, aa->parent, bb->parent, level + 1));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: a pointer to the lowest common ancestor node of the two given nodes.
 * If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	return (sa((binary_tree_t *) first, (binary_tree_t *) second,
				   (binary_tree_t *) first, (binary_tree_t *) second,
				   0));
}
