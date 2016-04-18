#include "hash_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[]) {
	FILE *f = fopen("test_add.txt", "a");
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
        if (i == rand_node){
            strcpy(rand_data, ftemp);
            //printf("str = %s strkey= %d\n",rand_data, strlen(rand_data));
        }    
    }
    printf("%s\n", rand_data);
   // printf("strkey= %d", strlen(rand_data));
     
    listnode *lkt ;
    double t = clock();
 	printf("%d\n", __LINE__);
    if (hashtab_lookup_add(hashtab, rand_data) == NULL){
		printf("%d\n", __LINE__);
		printf ("ERROR\n");
		exit(1);
		}
		else
		printf("%s\n", rand_data);
		printf("%d\n", __LINE__);
    lkt = hashtab_lookup_add(hashtab, rand_data);
    printf("%s %d\n", lkt->key, lkt->value);
    fprintf(f, "%d\t%.8f\n", size, (clock() - t) / CLOCKS_PER_SEC);


    printf("%s %d\n", lkt->key, lkt->value);
     
    fclose(f);
    fclose(dictionary);
	 
return 0;
}
