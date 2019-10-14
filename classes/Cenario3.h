#ifndef CENARIO3_H
#define CENARIO3_H
using namespace std;
#include <iostream>
#include <fstream>


class Cenario3
{
private:
int n;

public:
  Cenario3(); 
  ~Cenario3();    
  void quicksort();
  void insertion();
  void mergesort();
  void heapsort();
  void shellsort();
};

#endif // CENARIO3_H