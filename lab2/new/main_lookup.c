#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	FILE *f = fopen("test_lookup.txt", "a");
      
    FILE *dictionary = fopen("text.txt", "r");
    
    int i;
    int size = atoi(argv[1]);
    srand(time(NULL));
    int rand_node = rand() % size;
    
    //printf("%d\n", rand_node);
    

    char *rand_data = malloc(sizeof(char)*100);
    bstree *tree;
    
    
    for (i = 0; i < size; i++)
    {
		char *ftemp = malloc(sizeof(char)*100);
        fscanf(dictionary, "%s\n", ftemp);
        
        if (i == 0)
			tree = bstree_create(ftemp, i);
		else
			bstree_add(tree, ftemp, i);
			
  
        
        if (i == rand_node)
        {
            strcpy(rand_data, ftemp);
        }
    }
    //printf("%s\n", rand_data);
    
    
    bstree *lkt ;
    double t = clock();
    lkt = bstree_lookup(tree, rand_data);
    fprintf(f, "%d\t%.8f\n", size, (clock() - t) / CLOCKS_PER_SEC);
    printf("%s %d\n", lkt->key, lkt->value + 1);
    
    
    fclose(f);
    fclose(dictionary);
	 
return 0;
}
