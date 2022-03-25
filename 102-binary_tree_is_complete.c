#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * with level order traversal.
 *
 * @tree: pointer to the root node.
 * Return: 1 if complete, 0 otherwise or if NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue = NULL, **queue_check = NULL;
	binary_tree_t *tmp = NULL;
	int front = 0, rear = 0, i = 0, end = 500, flag = 0;

	queue = initial_checks((binary_tree_t *)tree, queue, end, &i);
	if (queue == NULL)
		return (free_queue_return_0(queue));
	queue[front] = (binary_tree_t *)tree;
	tmp = queue[front];
	while (tmp)
	{
		if (tmp->left)
		{
			if (flag)
				return (free_queue_return_0(queue));
			queue[++rear] = tmp->left;
		}
		else
			flag = 1;
		if (tmp->right)
		{
			if (flag)
				return (free_queue_return_0(queue));
			queue[++rear] = tmp->right;
		}
		else
			flag = 1;
		tmp = queue[++front];
		if (rear >= (end - 2))
		{
			end *= 2;
			queue_check = realloc(queue, end);
			if (realloc_checks(queue_check, end, i) == 0)
				return (free_queue_return_0(queue));
			queue = queue_check;
		}
	}
	free(queue);
	return (1);
}

/**
 * initial_checks - checks if tree is NULL and mallocs queue.
 *
 * @tree: pointer to binary tree root node.
 * @queue: queue to allocate memory for and initialize to NULL.
 * @end: size of queue.
 * @i: pointer to index for memory initialization.
 * Return: queue, or NULL if failed.
 */
binary_tree_t **initial_checks(binary_tree_t *tree, binary_tree_t **queue,
			       int end, int *i)
{
	if (tree == NULL)
		return (NULL);
	queue = malloc(sizeof(binary_tree_t *) * end);
	if (queue == NULL)
		return (NULL);
	for ((*i) = 0; (*i) < end; (*i)++)
		queue[(*i)] = NULL;
	return (queue);
}

/**
 * realloc_checks - checks that realloc was successful
 * and initializes to NULL.
 *
 * @queue_check: queue to check if realloc worked.
 * @end: new size of queue.
 * @i: old size of queue.
 * Return: 1 if successful, 0 if failed.
 */
int realloc_checks(binary_tree_t **queue_check, int end, int i)
{
	if (queue_check == NULL)
		return (0);
	for (; i < end; i++)
		queue_check[i] = NULL;
	return (1);
}

/**
 * free_queue_return_0 - frees the queue and returns 0 for failure.
 *
 * @queue: queue to free.
 * Return: 0 for incomplete binary tree or failure.
 */
int free_queue_return_0(binary_tree_t **queue)
{
	free(queue);
	return (0);
}
