#include "bstree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Create tree */
bstree *bstree_create(char *key, int value)
{
	
	bstree *tr;
	tr = malloc(sizeof(*tr));
	if (tr == NULL) {
		return tr;
	}
	
	tr->key = key;
	tr->value = value;
	tr->left = NULL;
	tr->right = NULL;
	
	return tr;	
}

/* Add new element(key, value) in tree */
bstree *bstree_add(bstree *tree, char *key, int value)
{	
	/*if the node is empty, then create the node */
	if (tree == NULL) {
		tree = bstree_create(key, value);
		return tree;
	}
	
	int cmp = strcmp(key, tree->key);
	bstree *tr, *root;
	tr = bstree_create(key, value);
	root = tree;
	
	/* if the node already exsist */
	if (cmp == 0) {
		tree->value = value;
		return tree;
	} else if (cmp < 0) {
		tree->left = bstree_add(tree->left, key, value);
	} else {
		tree->right = bstree_add(tree->right, key, value);
	}
	return root;
}

/* Lookup *key in tree */
bstree *bstree_lookup(bstree *tree, char *key)
{
	/* if tree is empty */
	if (tree == NULL) {
		return NULL;
	}
	
    int cmp = strcmp(key, tree->key);
   
	if (cmp == 0) {
		return tree;
	} else if (cmp < 0) {
		return bstree_lookup(tree->left, key);
	} else {
		return bstree_lookup(tree->right, key);
	}
}

bstree *bstree_min(bstree *tree)
{
	if (tree == NULL)
		return NULL;
		
    while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree)
{	
	if (tree == NULL)
		return NULL;
		
    while (tree->left != NULL) {
		tree = tree->right;
	}
	return tree;
}
