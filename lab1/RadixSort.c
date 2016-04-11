#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

void radixSort(int *a, int n);
int findLargestNum(int *a, int n);
void printArray(int *a, int n);

double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char *argv[]) {
	//int n = 500000; // array size
	if (argc < 2) {
		fprintf(stderr, "Too many actual parameters\n");
    	exit(EXIT_FAILURE);	
	}
    int n = atoi(argv[1]); 
    uint32_t *a; 
    a = malloc(sizeof(uint32_t) * n);
    if (a == NULL){
    	fprintf(stderr, "No enough memory\n");
    	exit(EXIT_FAILURE);
	}
    int i;
    for (i = 0; i < n; i++)
    	a[i] = (double)rand()/(RAND_MAX + 1.0) * 100001;
    //printf("Unsorted array:\n");
    //printArray(a, n); // vivod neotsortirovannogo massiva
    //printf("\n");
    double t = wtime(); // time before sort
    radixSort(a, n); // sort
    t = wtime() - t; // time after sort
    //printf("\nSorted List:\n");
    //printArray(a, n);
    //printf("\n");
    printf("NumberOfElements\tSortTime: \n");
    printf("%d\t\t\t%.6f sec\n", n, t);
    free(a);
    return 0;
}

// Radix Sort
void radixSort(int *a, int n) {
	int i;
  	int semiSorted[n];
  	int significantDigit = 1;
  	int largestNum = findLargestNum(a, n);
  	while (largestNum / significantDigit > 0) { // Loop until we reach the largest significant digit
    	//printf("Sorting: %d's place\n", significantDigit);
    	//printArray(a, n);
    	int bucket[10] = { 0 }; // Counts the number of "keys" or digits that will go into each bucket
    	for (i = 0; i < n; i++)
    		bucket[(a[i] / significantDigit) % 10]++;
  		/*
    	Add the count of the previous buckets,
    	Acquires the indexes after the end of each bucket location in the array
		Works similar to the count sort algorithm
  		*/
    	for (i = 1; i < 10; i++)
    		bucket[i] += bucket[i - 1];
  		// Use the bucket to fill a "semiSorted" array
    	for (i = n - 1; i >= 0; i--)
    		semiSorted[--bucket[(a[i] / significantDigit) % 10]] = a[i];
    	for (i = 0; i < n; i++)
    		a[i] = semiSorted[i];
    	significantDigit *= 10; // Move to next significant digit
    	//printf("\nBucket: ");
    	//printArray(bucket, 10);
  	}
}

int findLargestNum(int *a, int n) {
  	int i;
  	int largestNum = -1;
  	for (i = 0; i < n; i++) {
    	if (a[i] > largestNum)
    		largestNum = a[i];
	}
  	return largestNum;
}

void printArray(int *a, int n)
{
  	int i;
  	printf("[ ");
  	for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  	printf("]\n");
}
