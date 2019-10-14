#include "../classes/Cenario3.h"


#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


Cenario3::Cenario3(){
  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nINICIO CENARIO 3!\n");
  arquivo->fechar();
  delete arquivo;
}

Cenario3::~Cenario3(){
    Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\nFIM CENARIO 3\n");
  arquivo->fechar();
  delete arquivo;
}

void Cenario3::quicksort(){
}

void Cenario3::insertion(){
}

void Cenario3::mergesort(){
}

void Cenario3::heapsort(){
}

void Cenario3::shellsort(){
}