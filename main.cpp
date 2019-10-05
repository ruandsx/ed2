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

using namespace std;
int main(){
  srand(time(NULL));


  Cenario1 *cen1 = new Cenario1;
  cen1->iniciar();
  delete cen1;

  return 0;
  
}