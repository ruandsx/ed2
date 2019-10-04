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
using namespace std::chrono;
using namespace std;
#include "cpps/QuicksortMediana.cpp"
#include "classes/QuicksortMediana.h"

using namespace std;
int main(){

  int vetor[] = { 10, 45, 39, 1, 12, 35, 44};

  QuicksortMediana *quicksort = new QuicksortMediana();
  quicksort->ordenar(vetor, 0, 5);
  quicksort->print();
  delete quicksort;

  
  cout << "[";
    for(auto i = 0; i < 6; i++) {
        cout << vetor[i] << ", ";
    }
    cout << vetor[6] << "]" << endl;

  return 0;
}