#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* STRUCTS AND DEFINITIONS */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s bst_t;

typedef struct binary_tree_s avl_t;

typedef struct binary_tree_s heap_t;

/* FUNCTION PROTOTYPES */
/* provided print function prototypes */
void binary_tree_print(const binary_tree_t *tree);

/* function to insert new node (0) */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* function to insert new node as left child (1) */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* function to insert new node as right child (2) */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* function to remove node (3) */
void binary_tree_delete(binary_tree_t *tree);
/* function to determine if the given node is a leaf (4) */
int binary_tree_is_leaf(const binary_tree_t *node);
/* function to determine if the node is the root (5) */
int binary_tree_is_root(const binary_tree_t *node);
/* function to traverse tree using pre-order; run function at each node (6)*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* function to traverse tree using in-order; run function at each node (7)*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* function to traverse tree using post-order; run function at each node (8)*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* function to find tree's height, starting from given node (9)*/
size_t binary_tree_height(const binary_tree_t *tree);
/* subfunction to recursively help binary_tree_height find height */
size_t height_helper(const binary_tree_t *tree);
/* funciton to find tree's depth at current node (10)*/
size_t binary_tree_depth(const binary_tree_t *tree);
/* subfunction to recursively help binary_tree_depth find depth */
size_t depth_helper(const binary_tree_t *tree);
/* function to measure the size of the tree, starting from given node (11)*/
size_t binary_tree_size(const binary_tree_t *tree);
/* function to count the number of leaves in the tree (12)*/
size_t binary_tree_leaves(const binary_tree_t *tree);
/* function to count the number of nodes with at least 1 child in tree (13)*/
size_t binary_tree_nodes(const binary_tree_t *tree);
/* function to measure the balance factor of a binary tree (14)*/
int binary_tree_balance(const binary_tree_t *tree);
/* function to determine if the binary tree is full (15) */
int binary_tree_is_full(const binary_tree_t *tree);
/* helper function for task 15, determines if node has two children */
size_t two_children(const binary_tree_t *tree);
/* function to determine if the binary tree is perfect (16) */
int binary_tree_is_perfect(const binary_tree_t *tree);
/* function to find the sibling of a given node (17)*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/* function to find the aunt/uncle of a given node (18)*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
/* function to find the lowest common ancestor of two nodes (19)*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
/* helper function for binary_trees_ancestor to find ancestor recursively */
binary_tree_t *ancestor_finder(binary_tree_t *first_mover,
			       binary_tree_t *second_mover);
/* function that goes through a binary tree using level-order traversal (20)*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
/* helper function for level order traversal */
void current_level(const binary_tree_t *tree, size_t level, void (*func)(int));
/* function to determine if binary tree is complete (21)*/
int binary_tree_is_complete(const binary_tree_t *tree);
/* helper function for is_complete for NULL checks and queue initialization */
binary_tree_t **initial_checks(binary_tree_t *tree, binary_tree_t **queue,
			       int end, int *i);
/* helper function for is_complete to check if realloc successful */
int realloc_checks(binary_tree_t **queue_check, int end, int i);
/* helper function for is_complete to free queue and return if failed */
int free_queue_return_0(binary_tree_t **queue);
/* function that performs a left-rotation on a binary tree (22)*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
/* function that performs a right-rotation on a binary tree (23)*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
/* function to determine if tree is valid binary search tree (24)*/
int binary_tree_is_bst(const binary_tree_t *tree);
/*helper function to recursively check if binary search tree */
int is_bst_recursive(binary_tree_t *tree, int min, int max);
/* function to insert value into binary search tree (25)*/
bst_t *bst_insert(bst_t **tree, int value);
/* helper function to find location of insert for bst_insert */
bst_t *location_finder(bst_t *tree, int value);
/* function to create binary search tree from array of integers (26)*/
bst_t *array_to_bst(int *array, size_t size);
/* function that searches for a value in a Binary Search Tree (27)*/
bst_t *bst_search(const bst_t *tree, int value);
/* function to remove node from bst, replace with inorder successor (28)*/
bst_t *bst_remove(bst_t *root, int value);
/* helper function to find node to remove */
bst_t *bst_search2(const bst_t *tree, int value);
/* helper function to set right side if removed node had right child*/
bst_t *set_right(bst_t **root, bst_t *rm_node);

#endif
