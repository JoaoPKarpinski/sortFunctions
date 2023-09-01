#include <stdio.h>
#include <stdlib.h>
#include "quickSort.c" // pivo = 1
#include "insertionSort.c"
#include "mergeSort.c"
#include "selectionSort.c" //
#include "countingSort.c" //


int* copiaVetor(int* vet, int n){
  int* vetorCpy = (int*)malloc(sizeof(int) * n);

  for(int i = 0; i < n; i++){
    vetorCpy[i] = vet[i];
  }

  return vetorCpy;
}


int main(){
	int v1[] = {0,2,1,4,3,6,5,8,7};

	int* v2 = copiaVetor(v1, 9);

	quickSort(v2, 1, 9);

	for(int i = 0; i < 9; i++){
		printf("num v1 -> %d    ||    num v2 -> %d \n", v1[i], v2[i]);
	}
	/*
	int nn = 50;

	int n = (nn * 0.9);

	printf("%d\n", n);
	*/

	return 0;
}

/*
    4 vetores:
        random
        ordenado
        quase-ordenado
        reverso
*/