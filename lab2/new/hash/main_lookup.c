#include "hash_tab.h"
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
    hashtab_init(hashtab);
    
    for (i = 0; i < size; i++) {
		char *ftemp = malloc(sizeof(char)*100);
        fscanf(dictionary, "%s\n", ftemp);
		hashtab_add(hashtab, ftemp, i);
        if (i == rand_node)
            strcpy(rand_data, ftemp);
    }
    //printf("%s\n", rand_data);
    //printf("strkey= %d", strlen("dsfsad"));
    
    listnode *lkt ;
    double t = clock();
    
    lkt = hashtab_lookup(hashtab, rand_data);
    fprintf(f, "%d\t%.8f\n", size, (clock() - t) / CLOCKS_PER_SEC);
    printf("%s %d\n", lkt->key, lkt->value);

    fclose(f);
    fclose(dictionary);
	 
return 0;
}
