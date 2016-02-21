#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

// tekushee vremya "WallTime"
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char * argv[])
{
	int n = 100; // razmer massiva
    //int n = atoi(argv[1]); // zanosim razmer massiva v "n", vvedenniy kak parametr v terminale
    uint32_t *a; // ukazatel' na massiv
    a = malloc(sizeof(uint32_t) * n); // dinami4eskoe videlenie pamyati pod massiv
    if (a == NULL) { // pamyat' pod massiv ne videlilas'
    fprintf(stderr, "No enough memory\n");
    exit(EXIT_FAILURE);
}
    int i;
    for(i=0; i<n; i++) { // zapolnenie massiva
    a[i] = (double) rand()/(RAND_MAX + 1.0) * 100001;
}
    printf("Neotsortirovanniy massiv:\n");
    printArray(a, n); // vivod neotsortirovannogo massiva
    printf("\n");

    double t = wtime(); // vremya do sortirovki
    radixSort(a, n); // sortirovka
    printf("\nSorted List:\n");
    printArray(a, n);
    
    printf("\nRazmer massiva\tSortirovka dlilas': \n");
    t = wtime() - t; // uznaem skol'ko shla sortirovka
    printf("%d\t\t%.6f sec\n", n, t);
    free(a);
    return 0;
}

// Radix Sort
void radixSort(int * a, int n){
  // Base 10 is used
  int i;
  int semiSorted[n];
  int significantDigit = 1;
  int largestNum = findLargestNum(a, n);
  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){
    printf("Sorting: %d's place\n", significantDigit);
    printArray(a, n);
    
    int bucket[10] = { 0 };
    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < n; i++)
      bucket[(a[i] / significantDigit) % 10]++;
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    // Use the bucket to fill a "semiSorted" array
    for (i=n-1; i>=0; i--)
      semiSorted[--bucket[(a[i] / significantDigit) % 10]] = a[i];
    
    for (i = 0; i < n; i++)
      a[i] = semiSorted[i];
    // Move to next significant digit
    significantDigit *= 10;
    
    printf("\nBucket: ");
    printArray(bucket, 10);
  }
}

// Poisk naibol'shego 4isla v massive
int findLargestNum(int * a, int n){
  int i;
  int largestNum = -1;
  
  for(i = 0; i < n; i++){
    if(a[i] > largestNum)
      largestNum = a[i];
  }
  return largestNum;
}

// Procedura vivoda massiva
void printArray(int * a, int n){
  int i;
  printf("[ ");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("]\n");
}
