#include "../classes/Cenario4.h"

#include "../cpps/hashTable.cpp"
#include "../cpps/endSeparado.cpp"
#include "../cpps/endCoalescido.cpp"

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
    Arquivo *arquivo = new Arquivo();
    stringstream string1, string2, string3;
    
    arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
    arquivo->gravar("\n\nSondagem Linear:\n");
    arquivo->fechar();

    for(int i=1; i<=tamanhos[0]; i++){
        int vetor[tamanhos[i]];
        for(int j=0; j<5; j++){

          arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
          arquivo->montarVetor(vetor, tamanhos[i]);
          arquivo->fechar();

          hashTable *h = new hashTable(tamanhos[i]*2);
          h->criaTabela();

          auto start = high_resolution_clock::now();
          for(int k=0; k<tamanhos[i]; k++){
            h->sondagemLinear(vetor[k]);
          }
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<nanoseconds>(stop - start);       

          string1 << "Tempo na execucao " << j+1 << " com tabela tam = " << tamanhos[i] << " : "<< duration.count() << " nanosegundos" << endl;
          string2 << "Comparacoes de chaves feitas: " << h->getComparacoes() << endl;
          string3 << "Memoria gasta: " << h->getMemoria()  << "bytes" << endl << endl;
          
          arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
          arquivo->gravar(string1.str());
          arquivo->gravar(string2.str());
          arquivo->gravar(string3.str());
          arquivo->fechar();
          delete h;

          string1.str("");
          string2.str("");
          string3.str("");        
        }

    }

}

void Cenario4::sondagemQuadratica(){
  Arquivo *arquivo = new Arquivo();
  stringstream string1, string2, string3;
  
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nSondagem Quadratica:\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
      int vetor[tamanhos[i]];
      for(int j=0; j<5; j++){

        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
        arquivo->montarVetor(vetor, tamanhos[i]);
        arquivo->fechar();

        hashTable *h = new hashTable(tamanhos[i]*2);
        h->criaTabela();

        auto start = high_resolution_clock::now();
        for(int k=0; k<tamanhos[i]; k++){
          h->sondagemQuadratica(vetor[k]);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);       

        string1 << "Tempo na execucao " << j+1 << " com tabela tam = " << tamanhos[i] << " : "<< duration.count() << " nanosegundos" << endl;
        string2 << "Comparacoes de chaves feitas: " << h->getComparacoes() << endl;
        string3 << "Memoria gasta: " << h->getMemoria()  << "bytes" << endl << endl;
        
        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
        arquivo->gravar(string1.str());
        arquivo->gravar(string2.str());
        arquivo->gravar(string3.str());
        arquivo->fechar();
        delete h;

        string1.str("");
        string2.str("");
        string3.str("");        
      }

  }
}

void Cenario4::duploHash(){
    Arquivo *arquivo = new Arquivo();
  stringstream string1, string2, string3;
  
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nDuplo Hash:\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
      int vetor[tamanhos[i]];
      for(int j=0; j<5; j++){

        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
        arquivo->montarVetor(vetor, tamanhos[i]);
        arquivo->fechar();

        hashTable *h = new hashTable(tamanhos[i]*2);
        h->criaTabela();

        auto start = high_resolution_clock::now();
        for(int k=0; k<tamanhos[i]; k++){
          h->doubleHashing(vetor[k]);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);       

        string1 << "Tempo na execucao " << j+1 << " com tabela tam = " << tamanhos[i] << " : "<< duration.count() << " nanosegundos" << endl;
        string2 << "Comparacoes de chaves feitas: " << h->getComparacoes() << endl;
        string3 << "Memoria gasta: " << h->getMemoria()  << "bytes" << endl << endl;
        
        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
        arquivo->gravar(string1.str());
        arquivo->gravar(string2.str());
        arquivo->gravar(string3.str());
        arquivo->fechar();
        delete h;

        string1.str("");
        string2.str("");
        string3.str("");        
      }

  }
}

void Cenario4::encadeamentoSeparado(){
  Arquivo *arquivo = new Arquivo();
  stringstream string1, string2, string3;
  
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nEncadeamento Separado:\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
      int vetor[tamanhos[i]];
      for(int j=0; j<5; j++){

        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
        arquivo->montarVetor(vetor, tamanhos[i]);
        arquivo->fechar();

        endSeparado *e = new endSeparado(tamanhos[i]*2);

        auto start = high_resolution_clock::now();
        for(int k=0; k<tamanhos[i]; k++){
           e->insereItem(vetor[k]);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);       

        string1 << "Tempo na execucao " << j+1 << " com tabela tam = " << tamanhos[i] << " : "<< duration.count() << " nanosegundos" << endl;
        string2 << "Comparacoes de chaves feitas: " << e->getComparacoes() << endl;
        string3 << "Memoria gasta: " << e->getMemoria() << "bytes" << endl << endl;
        
        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
        arquivo->gravar(string1.str());
        arquivo->gravar(string2.str());
        arquivo->gravar(string3.str());
        arquivo->fechar();
        delete e;

        string1.str("");
        string2.str("");
        string3.str("");        
      }

  }

}

void Cenario4::encadeamentoCoalescido(){

  unsigned numColisoes = 0;
  
  Arquivo *arquivo = new Arquivo();
  stringstream string1, string2, string3;
  
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nEncadeamento Coalescido:\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
      int vetor[tamanhos[i]];
      numColisoes = 0;
      for(int j=0; j<5; j++){

        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
        arquivo->montarVetor(vetor, tamanhos[i]);
        arquivo->fechar();

        endCoalescido *coalescido = new endCoalescido(tamanhos[i]);

        auto start = high_resolution_clock::now();
        for(int k=0; k<tamanhos[i]; k++){
            coalescido->insereItem(vetor[k], &numColisoes); 
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);       

        string1 << "Tempo na execucao " << j+1 << " com tabela tam = " << tamanhos[i] << " : "<< duration.count() << " nanosegundos" << endl;
        string2 << "Comparacoes de chaves feitas: " << numColisoes << endl;
        string3 << "Memoria gasta: " << tamanhos[i]*4 << "bytes" << endl << endl;
        
        arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
        arquivo->gravar(string1.str());
        arquivo->gravar(string2.str());
        arquivo->gravar(string3.str());
        arquivo->fechar();
        delete coalescido; 

        string1.str("");
        string2.str("");
        string3.str("");        
      }

  }          

}