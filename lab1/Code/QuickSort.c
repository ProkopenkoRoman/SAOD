#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

void Quick(int *a, int l, int r);
void PrintArray(int *a, int n);

double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char *argv[]) {
	//int n = 1000000; // array size
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
    	a[i] = (double)rand() / (RAND_MAX + 1.0) * 100001;
    //printf("Unsorted array:\n");
    //PrintArray(a, n);
    //printf("\n");
    double t = wtime(); // time before sort
    Quick(a, 0, n); // sort
    t = wtime() - t; // time after sort
    //printf("\nSorted array:\n");
    //PrintArray(a, n);
    //printf("\n");
    printf("NumberOfElements\tSortTime: \n");
    printf("%d\t\t\t%.6f sec\n", n, t);
    free(a);
    return 0;
}

// Quick Sort
void Quick(int *a, int l, int r) {
    int i, j;
    int x, buf;
    i = l;
    j = r;
    x = a[(l + r) / 2];
    do {
    	while (a[i] < x)
    		i++;
    	while (x < a[j])
    		j--;
    	if (i <= j) {
    		buf = a[i];
    		a[i] = a[j];
    		a[j] = buf;
    		i++;
    		j--;
		}
	} 
    while ( i <= j);
    if (l < j) 
		Quick(a, l, j);
    if (r > i) 
		Quick(a, i, r);
}

void PrintArray(int *a, int n) {
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("]\n");
}
