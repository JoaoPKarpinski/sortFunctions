#include <stdio.h>
#include <stdlib.h>

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
