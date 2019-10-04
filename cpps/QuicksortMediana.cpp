#include "../classes/QuicksortMediana.h"
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


QuicksortMediana::QuicksortMediana(){
  trocas = 0;
  comparacoes = 0;
}

QuicksortMediana::~QuicksortMediana(){
}

void QuicksortMediana::ordenar(int arr[], int low, int high){
    if (low < high)
    {
        int pi = particionar(arr, low, high);

        ordenar(arr, low, pi - 1);
        ordenar(arr, pi + 1, high);
    }

}

int QuicksortMediana::mediana(int *V, int low, int high)
{

  int a = 0, b = 0, c = 0;



  a = rand()%(high-low + 1) + low; // gera valores aleatorios entre dois valores (?). Foi o que eu achei na internet
  //cout << "MINIMO: " << low << " MAXIMO: " << high << " VALOR GERADO: " << a << endl;

  b = rand()%(high-low + 1) + low;
  //cout <<" VALOR GERADO: " << b << endl;

  c = rand()%(high-low + 1) + low;
  //cout <<" VALOR GERADO: " << c << endl;

  int vetor[3];
  vetor[0] = V[a];
  //cout <<" VALOR GERADO: " << vetor[0] << endl;
  vetor[1] = V[b];
  //cout <<" VALOR GERADO: " << vetor[1] << endl;
  vetor[2] = V[c];
  //cout <<" VALOR GERADO: " << vetor[2] << endl;

  int tamanho = 3;
  int mediana;
  int aux;

  for(int i=0;i<tamanho-1;i++){
        for(int j=i+1;j<tamanho;j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    mediana = vetor[1];

    for(int i = low; i < high; i++){
        if(V[i] == mediana){
            //cout << "VALOR QUE ESTOU RETORNANDO DO INDICE EH: " << i  << " VALOR ESCOLHIDO PARA MEDIANA EH: " << mediana << endl << endl;
            return i;
        }
    }
}

int QuicksortMediana::particionar(int arr[], int low, int high){

    int pivot, pivito;
    if(high - low > 3)
        pivito = mediana(arr,low,high);
    else{
      // pivot = arr[high];
        pivito = high;
    }
    pivot = arr[pivito];
    trocar(&arr[pivito], &arr[high]);

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

void QuicksortMediana::trocar(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    trocas++;
}

void QuicksortMediana::print(){

  cout << trocas << endl;
  cout << comparacoes << endl;

}