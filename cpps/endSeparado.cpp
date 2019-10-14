#include<iostream> 
#include <list> 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <chrono>

#include"endSeparado.h"

using namespace std;

endSeparado::endSeparado(int b){
    this->baldes = b;
    tabela = new list<int>[baldes];
}

void endSeparado::insereItem(int x){
    int index = hashing(x,baldes);
    tabela[index].push_back(x);
}

void endSeparado::imprimeHashing() { 
  for (int i = 0; i < baldes; i++) { 
    cout << i; 
    for (auto x : tabela[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 

