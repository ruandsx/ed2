#include "../classes/QuicksortRecursivo.h"
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


QuicksortRecursivo::QuicksortRecursivo(){
  trocas = 0;
  comparacoes = 0;
}

QuicksortRecursivo::~QuicksortRecursivo(){
}

void QuicksortRecursivo::ordenar(int arr[], int low, int high){
    if (low < high)
    {
        int pi = particionar(arr, low, high);

        ordenar(arr, low, pi - 1);
        ordenar(arr, pi + 1, high);
    }

}

int QuicksortRecursivo::particionar(int arr[], int low, int high){

    int pivot;
   
    pivot = arr[high];

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

void QuicksortRecursivo::trocar(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    trocas++;
}

//daqui pra baixo será feita a ordenacao com a estrutura

void QuicksortRecursivo::criarStruct(int tamanho){
    srand(time(NULL));

    avaliacao avaliacoes[tamanho];

    int i=0, id, length;
    int tam = tamanho;
    string dados, lixo;
    leitor.open("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv");
    while(i<tamanho)
    {
        leitor.seekg(0, leitor.end);
        length = leitor.tellg(); //armazena quantos bytes tem o leitor total.
        leitor.seekg(0, leitor.beg);

        leitor.seekg(rand() % length, ios::beg); // procurar do inicio ate o fim do leitor
        getline(leitor, lixo);         // joga a linha no lixo
        getline(leitor, dados, ',');
        id = atof(dados.c_str());
        avaliacoes[i].id = id;
        i++;
    }
    leitor.close();
    
    ordenarStruct(avaliacoes, 0, tam-1);

    //delete avaliacoes;

}

void QuicksortRecursivo::ordenarStruct(avaliacao avaliacoes[], int low, int high){
    if (low < high)
    {
        int pi = particionarStruct(avaliacoes, low, high);

        ordenarStruct(avaliacoes, low, pi - 1);
        ordenarStruct(avaliacoes, pi + 1, high);
    }

}

int QuicksortRecursivo::particionarStruct(avaliacao avaliacoes[], int low, int high){

    int pivot;
    pivot = avaliacoes[high].id;
    //trocaStruct(&avaliacoes[high], &avaliacoes[high]);

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (avaliacoes[j].id <= pivot)
        {
            comparacoes++;
            i++;
            trocarStruct(&avaliacoes[i], &avaliacoes[j]);
        }
    }
    trocarStruct(&avaliacoes[i + 1], &avaliacoes[high]);
    return (i + 1);
}

void QuicksortRecursivo::trocarStruct(avaliacao* a, avaliacao* b){
    avaliacao t = *a;
    *a = *b;
    *b = t;
    trocas++;
}

//funcoes para pegar variaveis de classe
int QuicksortRecursivo::getTrocas(){
    return trocas;
}

int QuicksortRecursivo::getComparacoes(){
    return comparacoes;
}