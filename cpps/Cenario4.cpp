#include "../classes/Cenario4.h"
#include "../classes/hashTable.h"
#include "../classes/endSeparado.h"

#include "../cpps/hashTable.cpp"
#include "../cpps/endSeparado.cpp"

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;


Cenario4::Cenario4(){
  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("Relatório:\n\nINICIO CENARIO 4!\n");
  arquivo->fechar();

  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
  arquivo->getTamanhos(tamanhos);
  arquivo->fechar();


  delete arquivo;
}

Cenario4::~Cenario4(){
  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\nFIM CENARIO 4!\n");
  arquivo->fechar();
  delete arquivo;
}


void Cenario4::sondagemLinear(){

   for(int i=1; i<=tamanhos[0]; i++){
      int vetor[tamanhos[i]];
      hashTable *h = new hashTable(tamanho[i]*2);
      h->criaTabela();
      for(int j=0; j<5; j++){
        for(int k=0; k<tamanhos[i])
          h->sondagemLinear(vetor[k]);
      }
      delete h;
   }

}

void Cenario4::sondagemQuadratica(){
  
}

void Cenario4::duploHash(){
  
}

void Cenario4::encadeamentoSeparado(){
  //endSeparado *e = new endSeparado(10);
  //e->insereItem(valor);
}

void Cenario4::encadeamentoCoalescido(){
  
}