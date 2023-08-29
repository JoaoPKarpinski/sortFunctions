#include <stdio.h>
#include <stdlib.h>

int particiona(int *vetor, int p, int r) {
    int pivo = vetor[r];
    int i = p - 1;
    
    for (int j = p; j <= r - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
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
