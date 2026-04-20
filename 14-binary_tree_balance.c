#include "binary_trees.h"

/**
 * binary_tree_height - measures height in NODES (NOT edges)
 */
static size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left, right;

    if (tree == NULL)
        return (0);

    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);

    return (left > right ? left : right) + 1;
}

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: pointer to root node
 *
 * Return: balance factor or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height - right_height);
}
