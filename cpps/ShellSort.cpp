#include "../classes/ShellSort.h"
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


ShellSort::ShellSort(){
  trocas = 0;
  comparacoes = 0;
}

ShellSort::~ShellSort(){
}

void ShellSort::ordenar(int arr[], int n){

    int i, j, k;
    int aux;
    for(k = 1; k < n; k = 3*k+1);
      k = (k-1)/3;
      for(i = k; i < n; i++) {
        aux = arr[i];
        j = i;
        while(arr[j- k] > aux) {
            comparacoes++;
            arr[j] = arr[j-k];
            trocas++;
            j -= k;
            if(j < k) break;
          }
        arr[j] = aux;
        trocas++;
      }     

}

//funcoes para pegar variaveis de classe
int ShellSort::getTrocas(){
    return trocas;
}

int ShellSort::getComparacoes(){
    return comparacoes;
}