#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

void PrintArray(int *a, int n);
void OddEven(int *a, int n);
void swap(int *a, int i, int j);

double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char *argv[]) {
	//int n = 100000; // array size
	if (argc < 2) {
		fprintf(stderr, "Too many actual parameters\n");
    	exit(EXIT_FAILURE);	
	}
    int n = atoi(argv[1]);
    uint32_t *a;
    a = malloc(sizeof(uint32_t) * n);
    if (a == NULL) {
    	fprintf(stderr, "No enough memory\n");
    	exit(EXIT_FAILURE);
	}
    int i;
    for (i = 0; i < n; i++)
    	a[i] = (double) rand() / (RAND_MAX + 1.0) * 100001;
    //printf("Unsorted array:\n");
    //PrintArray(a, n);
    //printf("\n");
    double t = wtime(); // time before sort
    OddEven(a, n); // sort
    t = wtime() - t; // time after sort
    //printf("\nSorted array:\n");
    //PrintArray(a, n);
    //printf("\n");
    printf("NumberOfElements\tSortTime: \n");
    printf("%d\t\t\t%.6f sec\n", n, t);
    free(a);
    return 0;
}

// Odd-Even Sort
void OddEven(int *a, int n) {
    int sorted = 0, i, temp;
    while (sorted != 1) {
    	sorted = 1;
    	for (i = 1; i < n - 1; i += 2) {
    		if (a[i] > a[i + 1]) {
    			swap(a, i, i + 1);
    			sorted = 0;
			} 
		} 
    	for (i = 0; i < n - 1; i += 2){
    		if (a[i] > a[i + 1]) {
    			swap(a, i, i + 1);
    			sorted = 0;
			}
		}
	}
}

// Obmen elementov massiva
 void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
  
void PrintArray(int *a, int n) {
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("]\n");
}
