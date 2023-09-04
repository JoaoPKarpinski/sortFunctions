#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "selectionSort.c"
#include "insertionSort.c"
#include "mergeSort.c"
#include "heapSort.c"
#include "quickSort.c"
#include "countingSort.c"

void copiaVetor(int* vetDest, int* vetOrig, int n){
  for(int i = 0; i < n; i++){
    vetDest[i] = vetOrig[i];
  }
}

void geraVetor(int *vetor, int vTam) {
    for (int i = 0; i < vTam; i++) {
        vetor[i] = rand() % INT_MAX;
    }
}

//A saída deste experimento consiste de uma primeira linha contendo o rótulo [[REVERSE]],
//Ordena o vetor de Tamanho vTam em Ordem Decrescente
void ordenarDecrescente(int vetor[], int vTam) {
    for (int i = 0; i < vTam - 1; i++) {
        for (int j = 0; j < vTam - i - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

//A saída deste experimento consiste de uma primeira linha contendo um rótulo [[SORTED]]
//Ordena o vetor de Tamanho vTam em Ordem Crescente
void ordenarCrescente(int vetor[], int vTam) {
    for (int i = 0; i < vTam - 1; i++) {
        for (int j = 0; j < vTam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

//A saída deste experimento consiste de uma primeira linha contendo o rótulo [[NEARLY SORTED]]
// Quase ordena o vetor inteiro (Aproximadamente 90% do tamanho do vetor é ordenado...)
void quase_ordenar(int vetor[], int tamanho) {
    int fim_desordenado = tamanho * 0.10; 
    // Ordena a parte inicial do vetor (90% ordenado)
    for (int i = 0; i < fim_desordenado; i++) {
        for (int j = 0; j < fim_desordenado - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
  srand(time(NULL));

  int inc, fim, stp, rpt;
  scanf("%d %d %d", &inc, &fim, &stp);
  scanf("%d", &rpt);

  double SelectionA, InsertionA, MergeA, HeapA, QuickA, CoutingA;
  double SelectionD, InsertionD, MergeD, HeapD, QuickD, CoutingD;
  double SelectionO, InsertionO, MergeO, HeapO, QuickO, CoutingO;
  double SelectionQ, InsertionQ, MergeQ, HeapQ, QuickQ, CoutingQ;

  printf("[[RANDOM]]\n");
  printf("  n  Selection  Insertion   Merge     Heap      Quick    Couting\n");
  printf("-----------------------------------------------------------------\n");

  for (int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalHeap = 0, totalQuick = 0, totalCouting = 0;
      
    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      copiaVetor(tempoVetor, vetor, i);


      clock_t selectionInicio= clock();
      selectionSort(tempoVetor, i);
      clock_t selectionFinal = clock();
      totalSelection += ((double)(selectionFinal - selectionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t insertionInicio= clock();
      insertionSort(tempoVetor, i);
      clock_t insertionFinal= clock();
      totalInsertion += ((double)(insertionFinal - insertionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t mergeInicio= clock();
      mergeSort(tempoVetor, 0, i-1);
      clock_t mergeFinal= clock();
      totalMerge += ((double)(mergeFinal - mergeInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t heapInicio= clock();
      heapSort(tempoVetor, i);
      clock_t heapFinal= clock();
      totalHeap+= ((double)(heapFinal - heapInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t quickInicio= clock();
      quickSort(tempoVetor, 0, i-1);
      clock_t quickFinal= clock();
      totalQuick += ((double)(quickFinal - quickInicio)) / CLOCKS_PER_SEC;
        
      copiaVetor(tempoVetor, vetor, i);
      clock_t coutingInicio= clock();
      countingSort(tempoVetor,i);
      clock_t coutingFinal= clock();
      totalCouting += ((double)(coutingFinal - coutingInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 

    }

    SelectionA = totalSelection / rpt;
    InsertionA = totalInsertion / rpt;
    MergeA = totalMerge / rpt;
    HeapA = totalHeap / rpt;
    QuickA = totalQuick / rpt;
    CoutingA = totalCouting/rpt;

    printf("%d  %.6f  %.6f  %.6f  %.6f  %.6f  %.6f\n", i, SelectionA, InsertionA, MergeA, HeapA, QuickA, CoutingA);
  }

  printf("[[REVERSE]]\n");
  printf("  n  Selection  Insertion   Merge     Heap      Quick    Couting\n");
  printf("-----------------------------------------------------------------\n");

  for(int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalHeap = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);
      ordenarDecrescente(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      copiaVetor(tempoVetor, vetor, i);

      clock_t selectionInicio= clock();
      selectionSort(tempoVetor, i);
      clock_t selectionFinal = clock();
      totalSelection += ((double)(selectionFinal - selectionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t insertionInicio= clock();
      insertionSort(tempoVetor, i);
      clock_t insertionFinal= clock();
      totalInsertion += ((double)(insertionFinal - insertionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t mergeInicio= clock();
      mergeSort(tempoVetor, 0, i-1);
      clock_t mergeFinal= clock();
      totalMerge += ((double)(mergeFinal - mergeInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t heapInicio= clock();
      heapSort(tempoVetor, i);
      clock_t heapFinal= clock();
      totalHeap += ((double)(heapFinal - heapInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t quickInicio= clock();
      quickSort(tempoVetor, 0, i-1);
      clock_t quickFinal= clock();
      totalQuick += ((double)(quickFinal - quickInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t coutingInicio = clock();
      countingSort(tempoVetor,i);
      clock_t coutingFinal = clock();
      totalCouting += ((double)(coutingFinal - coutingInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 
    }

    SelectionD = totalSelection / rpt;
    InsertionD = totalInsertion / rpt;
    MergeD = totalMerge / rpt;
    HeapD = totalHeap / rpt;
    QuickD = totalQuick / rpt;
    CoutingD = totalCouting / rpt;
    HeapD = totalHeap / rpt;

    printf("%d  %.6f  %.6f  %.6f  %.6f  %.6f  %.6f\n", i, SelectionD, InsertionD, MergeD, HeapD, QuickD, CoutingD);
  }

  printf("[[SORTED]]\n");
  printf("  n  Selection  Insertion   Merge     Heap      Quick    Couting\n");
  printf("-----------------------------------------------------------------\n");

  for(int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalHeap = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);
      ordenarCrescente(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      copiaVetor(tempoVetor, vetor, i);

      clock_t selectionInicio= clock();
      selectionSort(tempoVetor, i);
      clock_t selectionFinal = clock();
      totalSelection += ((double)(selectionFinal - selectionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t insertionInicio= clock();
      insertionSort(tempoVetor, i);
      clock_t insertionFinal= clock();
      totalInsertion += ((double)(insertionFinal - insertionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t mergeInicio= clock();
      mergeSort(tempoVetor, 0, i-1);
      clock_t mergeFinal= clock();
      totalMerge += ((double)(mergeFinal - mergeInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t heapInicio= clock();
      heapSort(tempoVetor, i);
      clock_t heapFinal= clock();
      totalHeap += ((double)(heapFinal - heapInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t quickInicio= clock();
      quickSort(tempoVetor, 0, i-1);
      clock_t quickFinal= clock();
      totalQuick += ((double)(quickFinal - quickInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t coutingInicio= clock();
      countingSort(tempoVetor, i);
      clock_t coutingFinal= clock();
      totalCouting += ((double)(coutingFinal - coutingInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 
    }

    SelectionO = totalSelection / rpt;
    InsertionO = totalInsertion / rpt;
    MergeO = totalMerge / rpt;
    HeapO = totalHeap / rpt;
    QuickO = totalQuick / rpt;
    CoutingO = totalCouting/rpt;
    HeapO = totalHeap/rpt;

    printf("%d  %.6f  %.6f  %.6f  %.6f  %.6f  %.6f\n", i, SelectionO, InsertionO, MergeO, HeapO, QuickO, CoutingO);
  }

  printf("[[NEARLY SORTED]]\n");
  printf("  n  Selection  Insertion   Merge     Heap      Quick    Couting\n");
  printf("-----------------------------------------------------------------\n");

  for(int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalHeap = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);
      quase_ordenar(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      copiaVetor(tempoVetor, vetor, i);

      clock_t selectionInicio= clock();
      selectionSort(tempoVetor, i);
      clock_t selectionFinal = clock();
      totalSelection += ((double)(selectionFinal - selectionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t insertionInicio= clock();
      insertionSort(tempoVetor, i);
      clock_t insertionFinal= clock();
      totalInsertion += ((double)(insertionFinal - insertionInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t mergeInicio= clock();
      mergeSort(tempoVetor, 0, i-1);
      clock_t mergeFinal= clock();
      totalMerge += ((double)(mergeFinal - mergeInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t heapInicio= clock();
      heapSort(tempoVetor, i);
      clock_t heapFinal= clock();
      totalHeap += ((double)(heapFinal - heapInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t quickInicio= clock();
      quickSort(tempoVetor, 0, i-1);
      clock_t quickFinal= clock();
      totalQuick += ((double)(quickFinal - quickInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempoVetor, vetor, i);
      clock_t coutingInicio= clock();
      countingSort(tempoVetor,i);
      clock_t coutingFinal= clock();
      totalCouting += ((double)(coutingFinal - coutingInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 
    }

    SelectionQ = totalSelection / rpt;
    InsertionQ = totalInsertion / rpt;
    MergeQ = totalMerge / rpt;
    HeapQ = totalHeap / rpt;
    QuickQ = totalQuick / rpt;
    CoutingQ = totalCouting/rpt;
    HeapQ = totalHeap/rpt;

    printf("%d  %.6f  %.6f  %.6f  %.6f  %.6f  %.6f\n", i, SelectionQ, InsertionQ, MergeQ, HeapQ, QuickQ, CoutingQ);
  }

  return 0;
}