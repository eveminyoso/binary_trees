#include "binary_trees.h"
/**
 * find_successor - Finds the in-order successor of a node
 * @node: Pointer to the node
 *
 * Return: Pointer to the in-order successor
 */
bst_t *find_successor(bst_t *node)
{
	bst_t *succ = node->right;

	while (succ->left != NULL)
		succ = succ->left;
	return (succ);
}
/**
 * find_predecessor - Finds the in-order predecessor of a node
 * @node: Pointer to the node
 * Return: Pointer to the in-order predecessor
 */
bst_t *find_predecessor(bst_t *node)
{
	bst_t *pred = node->left;

	while (pred->right != NULL)
		pred = pred->right;
	return (pred);
}
/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *succ, *pred, *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;

			free(root);
			return (temp);
		}
		pred = find_predecessor(root);
		root->n = pred->n;
		root->left = bst_remove(root->left, pred->n);
		succ = find_successor(root);
		root->n = succ->n;
		root->right = bst_remove(root->right, succ->n);
	}
	return (root);
}
