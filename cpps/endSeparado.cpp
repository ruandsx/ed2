#include<iostream> 
#include <list> 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <chrono>

#include "../classes/endSeparado.h"

using namespace std;

endSeparado::endSeparado(int b){
    this->baldes = b;
    tabela = new list<int>[baldes];
    comparacoes = 0;
    tamanho = 0;
}

void endSeparado::insereItem(int x){
    int index = hashing(x,baldes);
    if(tabela[index].size()>0){
      comparacoes++;
    }
    tabela[index].push_back(x);
    tamanho++;
}

void endSeparado::imprimeHashing() { 
  for (int i = 0; i < baldes; i++) { 
    cout << i; 
    for (auto x : tabela[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 

int endSeparado::getComparacoes(){
  return comparacoes;
}

int endSeparado::getMemoria(){
  return tamanho * 4;
}