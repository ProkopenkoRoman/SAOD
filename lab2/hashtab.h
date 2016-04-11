#ifndef HESH_TAB
#define HESH_TAB

#define HASHTAB_SIZE 71
#define HASHTAB_MUL 31

typedef struct list_node {
	char *key;
	int value;
	struct listnode *next;
}listnode;

unsigned int hashtab_hash(char *key);
void hashtab_init( listnode **hashtab);
void hashtab_add(listnode **hashtab, char *key, int value);
listnode *hashtab_lookup(listnode **hashtab, char *key);
void hashtab_delete(listnode **hashtab, char *key);

listnode *hashtab[HASHTAB_SIZE];

#endif
