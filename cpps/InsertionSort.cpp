#include "../classes/InsertionSort.h"
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


InsertionSort::InsertionSort(){
  trocas = 0;
  comparacoes = 0;
}

InsertionSort::~InsertionSort(){
}

void InsertionSort::ordenar(int arr[], int n){

    int chave=0;
    for (int i = 1; i < n; i++) 
    {  
        chave = arr[i];  
        j = i - 1;  
  
        while (int j >= 0 && arr[j] > chave) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = chave;  
    }  

}

//funcoes para pegar variaveis de classe
int InsertionSort::getTrocas(){
    return trocas;
}

int InsertionSort::getComparacoes(){
    return comparacoes;
}