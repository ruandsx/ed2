#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


class MergeSort
{
private:
unsigned long int comparacoes;
unsigned long int trocas;
ifstream leitor;

public:
  MergeSort(); 
  ~MergeSort();    
  void ordenar(int arr[], int left, int right);
  void merge(int arr[], int left, int middle, int right);
  int getTrocas();
  int getComparacoes();

};

#endif // MERGESORT_H