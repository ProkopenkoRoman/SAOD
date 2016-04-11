#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	listnode *node;
	
	hashtab_init(hashtab);

	hashtab_add(hashtab, "Tigr", 190);
	hashtab_add(hashtab, "Slon", 2300);
	hashtab_add(hashtab, "Volk", 60);

	node = hashtab_lookup(hashtab, "Slon");

	printf("Node: %s, %d\n",node->key, node->value);
return 0;
}
