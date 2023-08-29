#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void geraVetor(int *vetor,int vTam) {
  int x;
  for (int i = 0; i < vTam; i++) {
    x = rand() % INT_MAX;
    vetor[i] = x;
  }
}
int menorElemento(int *vetor, int n, int ini) {
  int idx_menor = ini;
  for (int i = ini + 1; i < n; i++) {
    if (vetor[i] < vetor[idx_menor]) {
      idx_menor = i;
    }
  }
  return idx_menor;
}
void selectionSort(int *vetor, int n) {
  int idx, aux;
  for (int i = 0; i < n - 1; i++) {
    idx = menorElemento(vetor, n, i);
    aux = vetor[i];
    vetor[i] = vetor[idx];
    vetor[idx] = aux;
  }
}