#include "binary_trees.h"
/**
 * binary_tree_is_bst - Checks if a Binary search is a BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left && tree->left->n >= tree->n)
		return (0);
	if (tree->right && tree->right->n <= tree->n)
		return (0);
	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
}
/**
 * binary_tree_balance - measures the balance factor of a bst
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lft_h, rgt_h;

	if (tree == NULL)
		return (0);
	lft_h = binary_tree_height(tree->left);
	rgt_h = binary_tree_height(tree->right);
	return (lft_h - rgt_h);
}
/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return ((left > right ? left : right) + 1);
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (0);
	if (!binary_tree_is_bst(tree))
		return (0);
	balance_factor = binary_tree_balance(tree);
	if (balance_factor < -1 || balance_factor > 1)
		return (0);
	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
