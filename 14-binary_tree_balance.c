#include "binary_trees.h"

/**
 * binary_tree_height - correct node-based height
 * @tree: input binary tree
 * Return: tree height
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
 * binary_tree_balance - measures balance factor
 * @tree: input binary tree
 * Return: factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)binary_tree_height(tree->left) -
		(int)binary_tree_height(tree->right));
}
