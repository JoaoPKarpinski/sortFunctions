#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//implementando o selection sort
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

//implementando o insertion sort
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

//implementando o merge sort
void merge(int *vetor, int p, int q, int r) {
  int i, j, k;
  int n1 = q - p + 1;
  int n2 = r - q;
  int *left, *right;

  left = (int *)malloc((n1 + 1) * sizeof(int));
  right = (int *)malloc((n1 + 1) * sizeof(int));

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

//implementando o quick sort
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

//implementando o couting sort 
void countingSort(int array[], int tam){
  int max = array[0]; 
   
  for(int i = 1; i<tam; i++) {  
    if(array[i] > max){
      max = array[i];  
    }  
  }
    
  int cont[max + 1];

  for (int i = 0; i <= max; ++i){  
    cont[i] = 0;
  }  
    
  for (int i = 0; i < tam; i++){  
    cont[array[i]]++;  
  }  
  
  for(int i = 1; i<=max; i++) {  
    cont[i] += cont[i-1]; 
  }

  int saida[tam];

  for (int i = tam - 1; i >= 0; i--) {  
    saida[cont[array[i]] - 1] = array[i];  
    cont[array[i]]--;
  }
  
  for(int i = 0; i<tam; i++) {  
    array[i] = saida[i]; 
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