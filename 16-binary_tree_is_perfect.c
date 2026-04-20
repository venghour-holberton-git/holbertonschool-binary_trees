#include "binary_trees.h"

/**
 * get_depth - get depth
 * @tree: input tree
 */
static int get_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_rec - check is perfect rec
 * @tree: input tree
 * @depth: depth
 * @level: tree level
 */
static int is_perfect_rec(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_rec(tree->left, depth, level + 1) &&
		is_perfect_rec(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree);

	return (is_perfect_rec(tree, depth, 0));
}
