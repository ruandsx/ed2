#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


class InsertionSort
{
private:
long long int comparacoes;
long long int trocas;

public:
  InsertionSort(); 
  ~InsertionSort();    
  void ordenar(int arr[], int n);
  int getComparacoes();
  int getTrocas();
};

#endif // INSERTIONSORT_H