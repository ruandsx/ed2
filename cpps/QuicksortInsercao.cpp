#include "../classes/QuicksortInsercao.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;


QuicksortInsercao::QuicksortInsercao(){
  trocas = 0;
  comparacoes = 0;
}

QuicksortInsercao::~QuicksortInsercao(){
}

void QuicksortInsercao::ordenar(int arr[], int low, int high, int m){
    if (low < high)
    {
        if((high - low + 1) >= m){
            int pi = particionar(arr, low, high);

            ordenar(arr, low, pi - 1, m);
            ordenar(arr, pi + 1, high, m);
        }
        insertionSort(arr, high-low+1);
    }

}

int QuicksortInsercao::particionar(int arr[], int low, int high){

    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            comparacoes++;
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuicksortInsercao::insertionSort(int arr[], int n){
   
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        /* Move os elementos do arr que sao maiores que o pivô  
        para uma posicao na frente da atual*/
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
    
}

void QuicksortInsercao::trocar(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    trocas++;
}

//funcoes para pegar variaveis de classe
int QuicksortInsercao::getTrocas(){
    return trocas;
}

int QuicksortInsercao::getComparacoes(){
    return comparacoes;
}