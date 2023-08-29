#include <stdio.h>
#include <stdlib.h>

void insertion(int *vetor, int i) {
  int aux = vetor[i];
  for (int j = i - 1; j >= 0; j--) {
    if (vetor[j] < aux) {
      break;
    }
    vetor[j + 1] = vetor[j];
  }
}
void insertionSort(int *vetor, int n) {
  for (int i = 1; i < n; i++) {
    insertion(vetor, i);
  }
}