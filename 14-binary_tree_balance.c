#include "binary_trees.h"

/**
 * binary_tree_height_internal - helper to compute height
 */
static size_t binary_tree_height_internal(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height_internal(tree->left);
	right = binary_tree_height_internal(tree->right);

	return (left > right ? left : right) + (tree->left || tree->right);
}

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_internal(tree->left);
	right_height = binary_tree_height_internal(tree->right);

	return (left_height - right_height);
}
