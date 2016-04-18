#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTree
{
	char *key;
	int value;
	struct bstree *left;
	struct bstree *right;
} bstree;

bstree *bstree_create(char *name, int value);
bstree *bstree_add(bstree *tree, char *name, int value);
bstree *bstree_lookup(bstree *tree, char *name);
bstree *bstree_min(bstree *tree);
bstree *bstree_max(bstree *tree);

#endif
