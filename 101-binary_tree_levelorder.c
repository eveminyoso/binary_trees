#include "binary_trees.h"
/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t *current;
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);


	if (tree == NULL || func == NULL)
		return;

	/* Queue to store nodes at each level */
	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}
	free(queue);
}
