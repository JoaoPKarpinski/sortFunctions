#include <stdio.h>
#include <stdlib.h>

//implementando coutingSort
void countingSort(int vetor[], int n){
  int max = vetor[0]; 
   
  for(int i = 1; i<n; i++) {  
    if(vetor[i] > max){
      max = vetor[i];  
    }
  }
    
  int cont[max + 1];

  for (int i = 0; i <= max; ++i){  
    cont[i] = 0;
  }  
  for (int i = 0; i < n; i++){  
    cont[vetor[i]]++;  
  }  
  for(int i = 1; i<=max; i++) {  
    cont[i] += cont[i-1]; 
  }

  int saida[n];

  for (int i = n - 1; i >= 0; i--) {  
    saida[cont[vetor[i]] - 1] = vetor[i];  
    cont[vetor[i]]--;
  }
  for(int i = 0; i < n; i++) {  
    vetor[i] = saida[i]; 
  }
} 
