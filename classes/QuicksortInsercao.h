#ifndef QUICKSORTINSERCAO_H
#define QUICKSORTINSERCAO_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


class QuicksortInsercao
{
private:
long long int comparacoes;
long long int trocas;

public:
  QuicksortInsercao(); 
  ~QuicksortInsercao();    
  void ordenar(int arr[], int low, int high, int m);
  int particionar(int arr[], int low, int high);
  void insertionSort(int arr[], int n);
  void trocar(int* a, int* b);
  int getTrocas();
  int getComparacoes();

};

#endif // QUICKSORTINSERCAO_H