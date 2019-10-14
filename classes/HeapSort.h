#ifndef HEAPSORT_H
#define HEAPSORT_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


class HeapSort
{
private:
unsigned long int comparacoes;
unsigned long int trocas;

public:
  HeapSort();
  ~HeapSort();  
  void ordenar(int arr[], int n);
  void criaHeap(int vet[], int i, int f);
  int getComparacoes();
  int getTrocas();
};

#endif // HEAPSORT_H