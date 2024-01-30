#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if node provided is a root
 * @node: provided node value
 * Return: 1 if true and 0 if otherwise
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
