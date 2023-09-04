#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//implementando o merge sort
void merge(int *vetor, int p, int q, int r) {
  int i, j, k;
  int n1 = q - p + 1;
  int n2 = r - q;
  int *left, *right;

  left = (int *)malloc((n1 + 1) * sizeof(int));
  right = (int *)malloc((n2 + 1) * sizeof(int));

  for (i = 0; i < n1; i++) {
    left[i] = vetor[p + i];
  }
  for (j = 0; j < n2; j++) {
    right[j] = vetor[q + j + 1];
  }
  left[n1] = right[n2] = INT_MAX;
  i = j = 0;
  for (k = p; k <= r; k++) {
    if (left[i] <= right[j]) {
      vetor[k] = left[i];
      i++;
    } else {
      vetor[k] = right[j];
      j++;
    }
  }
  free(right);
  free(left);
}
void mergeSort(int *vetor, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        
        mergeSort(vetor, p, q);
        mergeSort(vetor, q + 1, r);
        merge(vetor, p, q, r);
    }
}
