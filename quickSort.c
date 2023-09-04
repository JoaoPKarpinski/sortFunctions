#include <stdio.h>
#include <stdlib.h>

//implementando o quick sort
int particiona(int *vetor, int p, int r) {
    int pivo = vetor[r];
    int i = p - 1, j, temp;
    
    for (j = p; j < r; j++) {
        if (vetor[j] <= pivo) {
            i++;
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    temp = vetor[i + 1];
    vetor[i + 1] = vetor[r];
    vetor[r] = temp;
    return i + 1;
}
void quickSort(int *vetor, int p, int r) {
    if (p < r) {
        int q = particiona(vetor, p, r);
        quickSort(vetor, p, q - 1);
        quickSort(vetor, q + 1, r);
    }
}
