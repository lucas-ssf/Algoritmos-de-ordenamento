#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

void mergesort(int array[], int tamanho);
int*merge(int a1[], int a2[], int tamanho1, int tamanho2);


int main(void) {
    int array[TAMANHO] = {10,8,5,3,9};
    mergesort(array, TAMANHO);
    for(int i = 0; i < TAMANHO; i++) printf("%d ", array[i]);
}

void mergesort(int array[], int tamanho) {
    int inicio = 0, fim = tamanho;
    if(tamanho > 3) {
        int meio = (inicio+fim)/2;
        int tamanho1 = meio;
        int tamanho2 = fim-(meio+1);
        int a1[tamanho1];
        int a2[tamanho2];
        for(int i = 0; i < tamanho1; i++)a1[i] = array[i];
        for(int i = 0; i < tamanho2; i++)a2[i] = array[meio + i];
        mergesort(a1, meio - inicio);
        mergesort(a2, fim - (meio+1));
        for(int i =0; i<(tamanho1+tamanho2); i++) array[i] = merge(a1,a2,tamanho1, tamanho2)[i];
    }


    for(int j = 0; j < tamanho; j++)
        for(int i = j+1; i < tamanho; i++)
            if(array[i] < array[j]) { //trocar valores sem intermediario
                array[j] = array[j] + array[i];
                array[i] = array[j] - array[i];
                array[j] = array[j] - array[i];
            }
}

int*merge(int a1[], int a2[], int tamanho1, int tamanho2) {
    int*a3 = (int*)malloc(sizeof(int)*(tamanho1+tamanho2));
    if(a3 != NULL){
        for(int i = 0; i<tamanho1; i++)a3[i] = a1[i];
        for(int i = 0; i<tamanho2; i++)a3[i+tamanho1] = a2[i];
    }else free(a3);
    return a3;
}