#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//Implementando o HeapSort


int heapPai(int filho){
    return (int)(filho-0.5)/2.0;
}
int heapFilhoEsq(int pai){
    return pai*2 + 1;
}
int heapFilhoDir(int pai){
    return pai*2 + 2;
}

void troca(int *v1, int *v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

void heapDesce(int v[], int n, int pai){
    int e,d,maior;

    e = heapFilhoEsq(pai);
    d = heapFilhoDir(pai);

    maior = pai;
    if (e < n && v[e] > v[pai]){
        maior = e;
    }
    if (d < n && v[d] > v[maior]){
        maior = d;
    }
    if (maior != pai){
        troca(&v[pai], &v[maior]);
        heapDesce(v,n,maior);
    }

}

void heapConstroi(int v[],int n){
    int i;
    int ultimo = n-1;
    for (i = heapPai(ultimo); i>=0; i--){
        heapDesce(v,n,i);
    }
}

int heapExtraiMax(int v[], int *n){
    int max = v[0];
    int ultimo = *n - 1;
    troca(&v[0], &v[ultimo]);
    heapDesce(v, ultimo, 0);
    *n = *n - 1;
    return max;
}

void heapSort(int v[],int n){
    int i;
    int max = n;
    heapConstroi(v,n);
    for (i = 0; i < max; i++){
        heapExtraiMax(v,&n);
    }
}