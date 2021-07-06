#include "rb_trees.h"
int isBST(const rb_tree_t *tree);
int diffHeight(const rb_tree_t *tree);

/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 * Notes: tree is NULL, return 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->color != BLACK)
		return (0);
	if (!isBST(tree))
		return (0);

	if (diffHeight(tree) > 1)
		return (0);

	return (1);
}
/**
 * diffHeight - is height-balanced binary tree
 * @tree: head of the tree
 * Return: 1 is true, 0 is false
 *
 */
int diffHeight(const rb_tree_t *tree)
{
	int diff;

	if (!tree)
		return (-1);
	diff = diffHeight(tree->left) - diffHeight(tree->right);
	if (diff >= 0)
		return (diff + 1);
	return (-diff + 1);
}

/**
 * isBST - is a binary search tree
 * @tree: head of the tree;
 * Return: 1 is true, 0 is false
 */
int isBST(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (isBST(tree->left) && isBST(tree->right))
	{
		if (tree->left && tree->right)
			return (tree->left->n < tree->n && tree->n < tree->right->n);
		if (tree->left)
			return (tree->left->n < tree->n);
		if (tree->right)
			return (tree->n < tree->right->n);
		return (1);
	}
	return (0);
}
