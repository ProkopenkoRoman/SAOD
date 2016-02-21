#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

void PrintArray(int * a, int n);
void OddEven(int *a, int n);
void swap(int *a, int i, int j);

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
    for(i=0; i<n; i++) // zapolnenie massiva
    a[i] = (double) rand()/(RAND_MAX + 1.0) * 100001;
    
    printf("Neotsortirovanniy massiv:\n");
    PrintArray(a, n); // vivod neotsortirovannogo massiva
    printf("\n");

    double t = wtime(); // vremya do sortirovki
    OddEven(a, n); // sortirovka
    printf("\nSorted List:\n");
    PrintArray(a, n);
    
    printf("\nRazmer massiva\tSortirovka dlilas': \n");
    t = wtime() - t; // uznaem skol'ko shla sortirovka
    printf("%d\t\t%.6f sec\n", n, t);
    free(a);
    return 0;
}

// Odd-Even Sort
void OddEven(int *a, int n)
{
    int sorted = 0, i, temp;
    while(sorted != 1){
      sorted = 1;
      for(i=1; i<n-1; i+=2){
       if(a[i] > a[i+1]){
        swap(a, i, i+1);
        sorted = 0;
      } 
    } 

    for(i=0; i<n-1; i+=2){
      if(a[i] > a[i+1]){
        swap(a, i, i+1);
        sorted = 0;
      }
    }
  }
}

// Obmen elementov massiva
 void swap(int * a, int i, int j )
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
  
// Procedura vivoda massiva
void PrintArray(int * a, int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("]\n");
}
