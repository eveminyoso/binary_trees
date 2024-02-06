#include "binary_trees.h"
/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node of the AVL Tree for insert
 * @value: Value to store in the created node, or NULL on fail
 * Return: Pointer to the created node,or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
	}
	else if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert(&((*tree)->right), value);
	else
		return (NULL);
	(*tree)->height = 1 + MAX(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));
	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (avl_right_rotate(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (avl_left_rotate(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = avl_left_rotate((*tree)->left);
		return (avl_right_rotate(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = avl_right_rotate((*tree)->right);
		return (avl_left_rotate(*tree));
	}
	return (*tree);
}
