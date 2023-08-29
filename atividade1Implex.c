#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "selectionSort.c"
#include "insertionSort.c"
#include "mergeSort.c"
#include "quickSort.c"
#include "countingSort.c "


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

  double SelectionA, InsertionA, MergeA, QuickA, CoutingA;
  double SelectionD, InsertionD, MergeD, QuickD, CoutingD;
  double SelectionO, InsertionO, MergeO, QuickO, CoutingO;
  double SelectionQ, InsertionQ, MergeQ, QuickQ, CoutingQ;

  printf("[[RANDOM]]\n");
  printf("n  Selection  Insertion  Merge  Quick  Couting\n");

  for (int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;
      
    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      memcpy(tempoVetor, vetor, sizeof(int) * i); 

      clock_t hrInicio, hrFinal;

      hrInicio = clock();
      selectionSort(tempoVetor, i);
      hrFinal = clock();
      totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      insertionSort(tempoVetor, i);
      hrFinal = clock();
      totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      mergeSort(tempoVetor, 0, i-1);
      hrFinal = clock();
      totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      quickSort(tempoVetor, 0, i-1);
      hrFinal = clock();
      totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      countingSort(tempoVetor, i-1);
      hrFinal = clock();
      totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 

    }

    SelectionA = totalSelection / rpt;
    InsertionA = totalInsertion / rpt;
    MergeA = totalMerge / rpt;
    QuickA = totalQuick / rpt;
    CoutingA = totalCouting / rpt;

    printf("%d %.6f %.6f %.6f %.6f %.6f\n", i, SelectionA, InsertionA, MergeA, QuickA, CoutingA);
  }

printf("[[REVERSE]]\n");
printf("n  Selection  Insertion  Merge  Quick  Couting\n");

  for(int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);
      ordenarDecrescente(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      memcpy(tempoVetor, vetor, sizeof(int) * i);

      clock_t hrInicio, hrFinal;

      hrInicio = clock();
      selectionSort(tempoVetor, i);
      hrFinal = clock();
      totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      insertionSort(vetor, i);
      hrFinal = clock();
      totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      mergeSort(tempoVetor, 0, i-1);
      hrFinal = clock();
      totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      quickSort(tempoVetor, 0, i-1);
      hrFinal = clock();
      totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      countingSort(tempoVetor, i-1);
      hrFinal = clock();
      totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 
    }

    SelectionD = totalSelection / rpt;
    InsertionD = totalInsertion / rpt;
    MergeD = totalMerge / rpt;
    QuickD = totalQuick / rpt;
    CoutingD = totalCouting / rpt;

    printf("%d %.6f %.6f %.6f %.6f %.6f\n", i, SelectionD, InsertionD, MergeD, QuickD, CoutingD);
  }

printf("[[SORTED]]\n");
printf("n  Selection  Insertion  Merge  Quick  Couting\n");

  for(int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      int * vetor = malloc(sizeof(int) * i);
      geraVetor(vetor, i);
      ordenarCrescente(vetor, i);

      int *tempoVetor = malloc(sizeof(int) * i); 
      memcpy(tempoVetor, vetor, sizeof(int) * i);

      clock_t hrInicio, hrFinal;

      hrInicio = clock();
      selectionSort(tempoVetor, i);
      hrFinal = clock();
      totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      insertionSort(vetor, i);
      hrFinal = clock();
      totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      mergeSort(tempoVetor, 0, i-1);
      hrFinal = clock();
      totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      quickSort(tempoVetor, 0, i-1);
      hrFinal = clock();
      totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      countingSort(tempoVetor, i-1);
      hrFinal = clock();
      totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      free(tempoVetor);
      free(vetor); 
    }

    SelectionO = totalSelection / rpt;
    InsertionO = totalInsertion / rpt;
    MergeO = totalMerge / rpt;
    QuickO = totalQuick / rpt;
    CoutingO = totalCouting / rpt;

    printf("%d %.6f %.6f %.6f %.6f %.6f\n", i, SelectionO, InsertionO, MergeO, QuickO, CoutingO);
  }

printf("[[NEARLY SORTED]]\n");
printf("n  Selection  Insertion  Merge  Quick  Couting\n");

for(int i = inc; i <= fim; i += stp) {
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
        int * vetor = malloc(sizeof(int) * i);
        geraVetor(vetor, i);
        quase_ordenar(vetor, i);

        int *tempoVetor = malloc(sizeof(int) * i); 
        memcpy(tempoVetor, vetor, sizeof(int) * i);

        clock_t hrInicio, hrFinal;

        hrInicio = clock();
        selectionSort(tempoVetor, i);
        hrFinal = clock();
        totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

        hrInicio = clock();
        insertionSort(vetor, i);
        hrFinal = clock();
        totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

        hrInicio = clock();
        mergeSort(tempoVetor, 0, i-1);
        hrFinal = clock();
        totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

        hrInicio = clock();
        quickSort(tempoVetor, 0, i-1);
        hrFinal = clock();
        totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

        hrInicio = clock();
        countingSort(tempoVetor, i-1);
        hrFinal = clock();
        totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

        free(tempoVetor);
        free(vetor); 
    }

    SelectionQ = totalSelection / rpt;
    InsertionQ = totalInsertion / rpt;
    MergeQ = totalMerge / rpt;
    QuickQ = totalQuick / rpt;
    CoutingQ = totalCouting / rpt;

    printf("%d %.6f %.6f %.6f %.6f %.6f\n", i, SelectionQ, InsertionQ, MergeQ, QuickQ, CoutingQ);
  }

  return 0;
}