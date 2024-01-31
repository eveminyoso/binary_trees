#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left != NULL)
		new_root->left->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;
	new_root->left = tree;

	/* If the original tree was the root, update the root pointer */
	if (new_root->parent == NULL)
	return (new_root);

	/* Update the parent's child pointer */
	if (new_root->parent->left == tree)
		new_root->parent->left = new_root;
	else
		new_root->parent->right = new_root;

	return (new_root);
}
