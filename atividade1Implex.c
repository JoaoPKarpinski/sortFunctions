#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "selectionSort.c"
#include "insertionSort.c"
#include "mergeSort.c"
#include "quickSort.c"
#include "countingSort.c"

/*

 SELECTIONSORT x
 INSERTIONSORT x
 MERGESORT x
 HEAPSORT --
 QUICKSORT x
 e
 COUNTINGSORT x

*/

void copiaVetor(int* vetDest, int* vetOrig, int n){
  for(int i = 0; i < n; i++){
    vetDest[i] = vetOrig[i];
  }
}

int* vetorAscendente(int n){
  int* vRetorno = (int*)malloc(sizeof(int) * n);

  for(int i = 0; i < n; i++){
    vRetorno[i] = i;
  }

  return vRetorno;
}

int* vetorAleatorio(int n){
  int* vRetorno = (int*)malloc(sizeof(int) * n);
  //srand(time(NULL));

  for(int i = 0; i < n; i++){
    vRetorno[i] = rand() % 20000;
  }

  return vRetorno;
}

int* vetorQuaseOrdenado(int n){
  int* vRetorno = (int*)malloc(sizeof(int) * n);
  int nOrd = (n * 0.9);

  for(int i = 0; i < nOrd; i++){
    vRetorno[i] = i;
  }

  for(int i = nOrd; i < n; i++){
    vRetorno[i] = rand() % 20000;
  }

  return vRetorno;
}

int* vetorDescendente(int n){
  int* vRetorno = (int*)malloc(sizeof(int) * n);

  for(int i = 0; i < n; i++){
    vRetorno[i] = n-i;
  }

  return vRetorno;
}

int main() {
  srand(time(NULL));

  int inc, fim, stp, rpt;
  scanf("%d %d %d", &inc, &fim, &stp);
  scanf("%d", &rpt);

  double SelectionA, InsertionA, MergeA, QuickA, CoutingA; // aleatório
  double SelectionD, InsertionD, MergeD, QuickD, CoutingD; // decrescente
  double SelectionO, InsertionO, MergeO, QuickO, CoutingO; // ordenado
  double SelectionQ, InsertionQ, MergeQ, QuickQ, CoutingQ; // quase ordenado

  printf("[[RANDOM]]\n");
  printf("n  Selection  Insertion  Merge  Quick  Couting\n");

  int* tempVetor;
  int* vetor;

  for (int i = inc; i <= fim; i += stp) { // aleatorio
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;
    vetor = vetorAleatorio(i);
    tempVetor = malloc(sizeof(int) * i);
    

    for (int j = 0; j < rpt; j++) {
      printf("chegou na 100\n");
      
      //free(tempVetor);
      printf("104\n");
      printf("106\n");
      copiaVetor(tempVetor, vetor, i);
      printf("108\n");

      clock_t hrInicio, hrFinal;

      printf("antes do selection\n");
      hrInicio = clock();
      selectionSort(tempVetor, i);
      hrFinal = clock();
      totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempVetor, vetor, i);
      
      printf("antes do insertion\n");
      hrInicio = clock();
      insertionSort(tempVetor, i);
      hrFinal = clock();
      totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      printf("antes do merge\n");
      hrInicio = clock();
      mergeSort(tempVetor, 0, i-1);
      hrFinal = clock();
      totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      copiaVetor(tempVetor, vetor, i);

      printf("antes do quick\n");
      hrInicio = clock();
      quickSort(tempVetor, 1, i);
      hrFinal = clock();
      totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      printf("linha 144\n");

      copiaVetor(tempVetor, vetor, i);

      printf("antes do counting\n");
      hrInicio = clock();
      countingSort(tempVetor, i-1);
      hrFinal = clock();
      totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

    }

    SelectionA = totalSelection / rpt;
    InsertionA = totalInsertion / rpt;
    MergeA = totalMerge / rpt;
    QuickA = totalQuick / rpt;
    CoutingA = totalCouting / rpt;

    printf("%d %.6f %.6f %.6f %.6f %.6f\n", i, SelectionA, InsertionA, MergeA, QuickA, CoutingA);
    free(vetor);
    free(tempVetor);
  }

printf("[[REVERSE]]\n");
printf("n  Selection  Insertion  Merge  Quick  Couting\n");

  for(int i = inc; i <= fim; i += stp) { // reverso
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      vetor = vetorDescendente(i);


      copiaVetor(tempVetor, vetor, i);

      clock_t hrInicio, hrFinal;

      hrInicio = clock();
      selectionSort(tempVetor, i);
      hrFinal = clock();
      totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      insertionSort(vetor, i);
      hrFinal = clock();
      totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      mergeSort(tempVetor, 0, i-1);
      hrFinal = clock();
      totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      quickSort(tempVetor, 1, i);
      hrFinal = clock();
      totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      countingSort(tempVetor, i-1);
      hrFinal = clock();
      totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


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

  for(int i = inc; i <= fim; i += stp) { // ordenado
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
      vetor = vetorAscendente(i);


      copiaVetor(tempVetor, vetor, i);

      clock_t hrInicio, hrFinal;

      hrInicio = clock();
      selectionSort(tempVetor, i);
      hrFinal = clock();
      totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      insertionSort(vetor, i);
      hrFinal = clock();
      totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

      hrInicio = clock();
      mergeSort(tempVetor, 0, i-1);
      hrFinal = clock();
      totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      quickSort(tempVetor, 1, i);
      hrFinal = clock();
      totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);

      hrInicio = clock();
      countingSort(tempVetor, i-1);
      hrFinal = clock();
      totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;


      copiaVetor(tempVetor, vetor, i);


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

for(int i = inc; i <= fim; i += stp) { // quase ordenado
    double totalSelection = 0, totalInsertion = 0, totalMerge = 0, totalQuick = 0, totalCouting = 0;

    for (int j = 0; j < rpt; j++) {
        vetor = vetorQuaseOrdenado(i);



        copiaVetor(tempVetor, vetor, i);

        clock_t hrInicio, hrFinal;



        copiaVetor(tempVetor, vetor, i);

        hrInicio = clock();
        selectionSort(tempVetor, i);
        hrFinal = clock();
        totalSelection += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;



        copiaVetor(tempVetor, vetor, i);

        hrInicio = clock();
        insertionSort(vetor, i);
        hrFinal = clock();
        totalInsertion += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;

        hrInicio = clock();
        mergeSort(tempVetor, 0, i-1);
        hrFinal = clock();
        totalMerge += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;



        copiaVetor(tempVetor, vetor, i);

        hrInicio = clock();
        quickSort(tempVetor, 1, i);
        hrFinal = clock();
        totalQuick += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;



        copiaVetor(tempVetor, vetor, i);

        hrInicio = clock();
        countingSort(tempVetor, i-1);
        hrFinal = clock();
        totalCouting += ((double)(hrFinal - hrInicio)) / CLOCKS_PER_SEC;



        copiaVetor(tempVetor, vetor, i);



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