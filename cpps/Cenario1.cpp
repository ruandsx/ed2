#include "../classes/Cenario1.h"
#include "../classes/Arquivo.h"
#include "Arquivo.cpp"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;


Cenario1::Cenario1(){
}

Cenario1::~Cenario1(){
}

void Cenario1::iniciar(){
  ifstream leitor;
  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("deu certo coroio");
  arquivo->fechar();
}

void Cenario1::ordenar(){

}