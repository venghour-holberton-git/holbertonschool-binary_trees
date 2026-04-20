#include "binary_trees.h"

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    if (tree->left)
    {
        const binary_tree_t *l = tree->left;
        left_height = 1;

        while (l->left || l->right)
        {
            if (l->left)
                l = l->left;
            else
                l = l->right;
            left_height++;
        }
    }

    if (tree->right)
    {
        const binary_tree_t *r = tree->right;
        right_height = 1;

        while (r->left || r->right)
        {
            if (r->left)
                r = r->left;
            else
                r = r->right;
            right_height++;
        }
    }

    return ((int)left_height - (int)right_height);
}
