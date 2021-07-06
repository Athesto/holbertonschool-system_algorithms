#include "rb_trees.h"
/**
 * rb_tree_node - creates a Red-Black Tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: value to put in the new node
 * @color: color of the node
 * Return: a pointer to the new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->n  = value;
	new->left = new->right = NULL;
	new->color = color;

	return (new);
}
