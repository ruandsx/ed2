#include "../classes/HeapSort.h"
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


HeapSort::HeapSort(){
  trocas = 0;
  comparacoes = 0;
}

HeapSort::~HeapSort(){
}

void HeapSort::ordenar(int vet[], int n){
    int i, aux;
    for(i=(n-1)/2; i >= 0; i--)
    {
        criaHeap(vet,i,n-1);
    }
    for (i = n-1; i>=1; i--) 
    {
        aux = vet[0]; //pega maior elemento da heap e coloca na sua posição correpondente no array
        vet[0] = vet[i];
        vet[i] = aux;
        trocas++;
        criaHeap(vet,0,i-1); //reconstruir heap
    }
}

void HeapSort::criaHeap(int vet[], int i, int f)
{
    int aux = vet[i];
    int j = i*2+1;
    while(j<=f)
    {
        if(j<f)
        {
            if(vet[j] < vet[j+1]) //pai tem dois filhos? Quem é o maior?
            {
                comparacoes++;
                j = j + 1;
            }
        }
        if(aux < vet[j]) //Filho maior que o pai? Filhp se torna pai! Repetir o processo
        {
            comparacoes++;
            vet[i] = vet[j];
            trocas++;
            i = j;
            j = 2*i+1;

        }
        else
        {
            j = f + 1;
        }

    }
    vet[i] = aux; //Antigo pai ocupa lugar do último filho analisado
    trocas++;
}

//funcoes para pegar variaveis de classe
int HeapSort::getTrocas(){
    return trocas;
}

int HeapSort::getComparacoes(){
    return comparacoes;
}