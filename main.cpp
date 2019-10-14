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
  return 0;
  
}