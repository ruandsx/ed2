#include "../classes/Cenario3.h"
#include "../classes/InsertionSort.h"
#include "../classes/ShellSort.h"

#include "../cpps/InsertionSort.cpp"
#include "../cpps/ShellSort.cpp"

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
  srand(time(NULL));

  int tamanhos[6];
  stringstream string1, string2, string3;

  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
  arquivo->getTamanhos(tamanhos);
  arquivo->fechar();
  //tamanhos[0] é o N e tamanhos[1,2,3,4] sao os tamanhos dos vetores, logo: 

  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nQuickSort:\n\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
    int vetor[tamanhos[i]];
    for(int j=0; j<5; j++){

      arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
      arquivo->montarVetor(vetor, tamanhos[i]);
      arquivo->fechar();

      QuicksortRecursivo *quicksort = new QuicksortRecursivo();

      auto start = high_resolution_clock::now();
      quicksort->ordenar(vetor, 0, tamanhos[i]-1);
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

    }
  }
  delete arquivo;
}

void Cenario3::insertion(){
  srand(time(NULL));

  int tamanhos[6];
  stringstream string1, string2, string3;

  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
  arquivo->getTamanhos(tamanhos);
  arquivo->fechar();
  //tamanhos[0] é o N e tamanhos[1,2,3,4] sao os tamanhos dos vetores, logo: 

  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nInsertionSort:\n\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
    int vetor[tamanhos[i]];
    for(int j=0; j<5; j++){

      arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
      arquivo->montarVetor(vetor, tamanhos[i]);
      arquivo->fechar();

      InsertionSort *insertions = new InsertionSort();

      auto start = high_resolution_clock::now();
      insertions->ordenar(vetor, tamanhos[i]-1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);       

      string1 << "Tempo na execucao " << j+1 << " com vetor tam = " << tamanhos[i] << " : "<< duration.count() << " microsegundos" << endl;
      string2 << "Comparacoes feitas: " << insertions->getComparacoes() << endl;
      string3 << "Trocas feitas: " << insertions->getTrocas() << endl << endl;
      
      delete insertions;
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

void Cenario3::mergesort(){
}

void Cenario3::heapsort(){
}

void Cenario3::shellsort(){
 srand(time(NULL));

  int tamanhos[6];
  stringstream string1, string2, string3;

  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
  arquivo->getTamanhos(tamanhos);
  arquivo->fechar();
  //tamanhos[0] é o N e tamanhos[1,2,3,4] sao os tamanhos dos vetores, logo: 

  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nShellSort:\n\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
    int vetor[tamanhos[i]];
    for(int j=0; j<5; j++){

      arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
      arquivo->montarVetor(vetor, tamanhos[i]);
      arquivo->fechar();

      ShellSort *shell = new ShellSort();

      auto start = high_resolution_clock::now();
      shell->ordenar(vetor, tamanhos[i]-1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<nanoseconds>(stop - start);       

      string1 << "Tempo na execucao " << j+1 << " com vetor tam = " << tamanhos[i] << " : "<< duration.count() << " nanosegundos" << endl;
      string2 << "Comparacoes feitas: " << shell->getComparacoes() << endl;
      string3 << "Trocas feitas: " << shell->getTrocas() << endl << endl;
      
      delete shell;
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