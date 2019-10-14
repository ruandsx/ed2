#include "../classes/MergeSort.h"
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


MergeSort::MergeSort(){
  trocas = 0;
  comparacoes = 0;
}

MergeSort::~MergeSort(){
}

void MergeSort::merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++){
        larr[i] = array[l+i];
        trocas++;
   }
   for(j = 0; j<nr; j++){
       rarr[j] = array[m+1+j];
       trocas++;
   }
      
   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
            comparacoes++;
            array[k] = larr[i];
            trocas++;
            i++;
      }else{
            comparacoes++;
            array[k] = rarr[j];
            trocas++;
            j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      trocas++;
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      trocas++;
      j++; k++;
   }
}

void MergeSort::ordenar(int array[], int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      ordenar(array, l, m);
      ordenar(array, m+1, r);
      merge(array, l, m, r);
   }
}


//funcoes para pegar variaveis de classe
int MergeSort::getTrocas(){
    return trocas;
}

int MergeSort::getComparacoes(){
    return comparacoes;
}