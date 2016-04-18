#ifndef HESH_TAB
#define HESH_TAB

#define HASHTAB_SIZE 900
#define HASHTAB_MUL 31

typedef struct list_node {
	char *key;
	int value;
	struct list_node *next;
} listnode;

unsigned int hashtab_hash(char *key);
void hashtab_init( listnode **hashtab);
void hashtab_add(listnode **hashtab, char *key, int value);
listnode *hashtab_lookup(listnode **hashtab, char *key);
void hashtab_delete(listnode **hashtab, char *key);
listnode *hashtab_lookup_add(listnode **hashtab, char *key);
unsigned add_hash(char *key, int len);

listnode *hashtab[HASHTAB_SIZE];

#endif
