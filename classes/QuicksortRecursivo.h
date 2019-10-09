#ifndef QUICKSORTRECURSIVO_H
#define QUICKSORTRECURSIVO_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "../classes/Avaliacao.h"


class QuicksortRecursivo
{
private:
long long int comparacoes;
long long int trocas;
ifstream leitor;

public:
  QuicksortRecursivo(); 
  ~QuicksortRecursivo();    
  void ordenar(int arr[], int low, int high);
  int particionar(int arr[], int low, int high);
  void criarStruct(int tamanho);
  void ordenarStruct(avaliacao arr[], int low, int high);
  int particionarStruct(avaliacao arr[], int low, int high);
  void trocar(int* a, int* b);
  void trocarStruct(avaliacao* a, avaliacao* b);
  int getTrocas();
  int getComparacoes();

};

#endif // QUICKSORTRECURSIVO_H