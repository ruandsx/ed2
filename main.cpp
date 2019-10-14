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
#include "cpps/Cenario1.cpp"
#include "classes/Cenario1.h"
#include "cpps/Cenario2.cpp"
#include "classes/Cenario2.h"
#include "cpps/Cenario3.cpp"
#include "classes/Cenario3.h"
#include "cpps/Cenario4.cpp"
#include "classes/Cenario4.h"

using namespace std;
int main(){
  srand(time(NULL));
  
  Cenario1 *cen1 = new Cenario1;
  cen1->vetorSimples();
  cen1->vetorStruct();
  delete cen1;

  Cenario2 *cen2 = new Cenario2;
  cen2->recursivo();
  cen2->mediana();
  cen2->insercao();
  delete cen2;
  
  Cenario3 *cen3 = new Cenario3;
  cen3->quicksort();
  cen3->insertion();
  cen3->mergesort();
  cen3->heapsort();
  cen3->shellsort();
  delete cen3;
  
  Cenario4 *cen4 = new Cenario4;
  cen4->sondagemLinear();
  cen4->sondagemQuadratica();
  cen4->duploHash();
  cen4->encadeamentoSeparado();
  cen4->encadeamentoCoalescido();
  delete cen4;


  return 0; 
}