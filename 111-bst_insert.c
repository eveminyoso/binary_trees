#include "binary_trees.h"
/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent, *current;

	if (tree == NULL)
		return (NULL);
	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (*tree == NULL)
	{
		/* If the tree is empty, set the new node as the root */
		new_node->parent = NULL;
		*tree = new_node;
		return (new_node);
	}
	current = *tree;
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
		{
			/* Value already exists, ignore and free the new node */
			free(new_node);
			return (NULL);
		}
	}
	new_node->parent = parent;
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}
