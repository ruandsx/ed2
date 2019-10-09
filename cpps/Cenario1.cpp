#include "../classes/Cenario1.h"
#include "../classes/Arquivo.h"
#include "../classes/QuicksortRecursivo.h"
//arquivos
#include "Arquivo.cpp"
#include "QuicksortRecursivo.cpp"

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;


Cenario1::Cenario1(){
}

Cenario1::~Cenario1(){
}

void Cenario1::vetorSimples(){
  int tamanhos[6];
  stringstream string1, string2, string3;

  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
  arquivo->getTamanhos(tamanhos);
  arquivo->fechar();
  //tamanhos[0] é o N e tamanhos[1,2,3,4] sao os tamanhos dos vetores, logo: 

  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("Relatório: \n\nVetor Simples:\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
    int vetor[tamanhos[i]];
    for(int j=0; j<5; j++){
      arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
      arquivo->montarVetor(vetor, tamanhos[i]);
      arquivo->fechar();

      QuicksortRecursivo *quicksort = new QuicksortRecursivo();

      
      auto start = high_resolution_clock::now();
      quicksort->ordenar(vetor, 0, tamanhos[i]);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);       

      string1 << "Tempo na execucao " << j+1 << " com vetor tam = " << tamanhos[i] << " : "<< duration.count() << " microsegundos" << endl;
      string2 << "Comparacoes feitas: " << quicksort->getComparacoes() << endl;
      string3 << "Trocas feitas: " << quicksort->getTrocas() << endl << endl;
      
      delete quicksort;
      arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
      arquivo->gravar(string1.str());
      arquivo->gravar(string2.str());
      arquivo->gravar(string3.str());
      arquivo->fechar();

      string1.str("");
      string2.str("");
      string3.str("");
      /*
      for(int i=0; i<1000; i++){
        cout << vetor[i] << " ";
      }
      cout << endl;
      */
    }
  }
    
  delete arquivo; 
}

void Cenario1::vetorStruct(){

    int tamanhos[6];
    stringstream string1, string2, string3;

    Arquivo *arquivo = new Arquivo();
    arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
    arquivo->getTamanhos(tamanhos);
    arquivo->fechar();
    //tamanhos[0] é o N e tamanhos[1,2,3,4] sao os tamanhos dos vetores, logo: 

    arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
    arquivo->gravar("\n\nVetor Struct:\n");
    arquivo->fechar();

    for(int i=1; i<=tamanhos[0]; i++){
      for(int j=0; j<4; j++){

        QuicksortRecursivo *quicksort = new QuicksortRecursivo();

        auto start = high_resolution_clock::now();
        quicksort->criarStruct(tamanhos[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);       

        string1 << "Tempo na execucao " << j+1 << " com vetor struct tam = " << tamanhos[i] << " : "<< duration.count() << " microsegundos" << endl;
        string2 << "Comparacoes feitas: " << quicksort->getComparacoes() << endl;
        string3 << "Trocas feitas: " << quicksort->getTrocas() << endl << endl;
        
        delete quicksort;
        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
        arquivo->gravar(string1.str());
        arquivo->gravar(string2.str());
        arquivo->gravar(string3.str());
        arquivo->fechar();

        string1.str("");
        string2.str("");
        string3.str("");
  

      }
    }
      
    delete arquivo; 
  }