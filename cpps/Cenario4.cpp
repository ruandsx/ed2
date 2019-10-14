#include "../classes/Cenario4.h"

//arquivos

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

}

void Cenario4::sondagemQuadratica(){
  
}

void Cenario4::duploHash(){
  
}

void Cenario4::encadeamentoSeparado(){
  
}

void Cenario4::encadeamentoCoalescido(){
  
}