#ifndef SHELLSORT_H
#define SHELLSORT_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


class ShellSort
{
private:
unsigned long int comparacoes;
unsigned long int trocas;

public:
  ShellSort(); 
  ~ShellSort();    
  void ordenar(int arr[], int n);
  int getComparacoes();
  int getTrocas();
};

#endif // SHELLSORT_H