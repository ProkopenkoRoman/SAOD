#include "hashtab.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int hashtab_hash(char *key) {
	unsigned int h = 0;
	char *p;
	for (p = key; *p != '\0'; p++) {
		h = h * HASHTAB_MUL + (unsigned int)*p;
	}
return h % HASHTAB_SIZE;
}

void hashtab_init(listnode **hashtab) {
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(listnode **hashtab, char *key, int value) {
	listnode *node;

	int index = hashtab_hash(key);
	// Вставка в начало списка
	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

listnode *hashtab_lookup(listnode **hashtab, char *key) {
	int index;
	listnode *node;

	index = hashtab_hash(key);
	for (node = hashtab[index];	node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0)
			return node;
	}
return NULL;
}
/*
void hashtab_delete(listnode **hashtab, char *key) {
	int index;
	struct listnode *p, *prev = NULL;
	index = hashtab_hash(key);
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL
				hashtab[index] = p->next;
			else
				prev->next = p->next;
			free(p);
			return;
		}
		prev = p;
	}
}
*/
