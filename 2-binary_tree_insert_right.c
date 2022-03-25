#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts new binary tree node as parent-right
 * if parent-right exists, becomes new node's right child.
 *
 * @parent: parent node of the node to create.
 * @value: value to put in the new node.
 * Return: pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node = NULL;

	if (parent == NULL)
		return (NULL);

	right_node = malloc(sizeof(binary_tree_t));
	if (right_node == NULL)
		return (NULL);

	right_node->n = value;
	right_node->parent = parent;
	right_node->left = NULL;
	right_node->right = NULL;

	right_node->right = parent->right;
	parent->right = right_node;

	if (right_node->right)
		right_node->right->parent = right_node;

	return (right_node);
}
