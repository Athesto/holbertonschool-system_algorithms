#include "rb_trees.h"
/**
 * rb_tree_insert - inserts a value in a Red-Black Tree
 * @tree: double pointer to the root node of the Red-Black tree
 * to insert the value in
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 * Notes:
 *  - If the address stored in tree is NULL,
 *  the created node must become the root node.
 *  - The resulting tree after insertion, must be a Red-Black Tree
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *parent, *uncle, *gparent, *runner;

	/* insert into root */
	if (!*tree)
	{
		*tree = rb_tree_node(NULL, value, BLACK);
		return (*tree);
	}

	/* append node */
	runner = *tree;
	while (runner)
	{
		parent = runner;
		if (runner->n < value)
			runner = runner->left;
		else
			runner = runner->right;
	}
	runner = rb_tree_node(parent, value, RED);
	if (runner->n < parent->n)
		parent->left = runner;
	else
		parent->right = runner;

	return (rb_tree_node(parent, value, BLACK));
	/* get family */
	gparent = parent->parent;
	if (gparent->left != parent)
		uncle = gparent->left;
	else
		uncle = gparent->right;

	/* fix uncle RED */
	if (parent->color == RED && uncle->color == RED)
	{
		parent->color = uncle->color = BLACK;
		gparent->color = RED;
		if (gparent->parent == NULL)
			gparent->color = BLACK;
		return (runner);
	}
	return (NULL);
}
