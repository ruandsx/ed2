#include "../classes/Cenario2.h"
#include "../classes/QuicksortInsercao.h"
#include "../cpps/QuicksortInsercao.cpp"

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


Cenario2::Cenario2(){
}

Cenario2::~Cenario2(){
}

void Cenario2::recursivo(){
}

void Cenario2::mediana(){
}

void Cenario2::insercao(){
  srand(time(NULL));

  int tamanhos[6];
  int mAtual = 10;
  stringstream string1, string2, string3;

  Arquivo *arquivo = new Arquivo();
  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/entrada.txt", 'l');
  arquivo->getTamanhos(tamanhos);
  arquivo->fechar();
  //tamanhos[0] é o N e tamanhos[1,2,3,4] sao os tamanhos dos vetores, logo: 

  arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/saida.txt", 'e');
  arquivo->gravar("\n\nQuicksortInsercao:\n\n");
  arquivo->fechar();

  for(int i=1; i<=tamanhos[0]; i++){
    int vetor[tamanhos[i]];
    for(int j=0; j<5; j++){

      (j%2==0)?mAtual=100:mAtual=10;

      arquivo->abrir("C:/Users/ruanl/Desktop/DocumentosFacul/Materias/ED2/assets/bgg-13m-reviews.csv", 'l');
      arquivo->montarVetor(vetor, tamanhos[i]);
      arquivo->fechar();

      QuicksortInsercao *insercao = new QuicksortInsercao();

      auto start = high_resolution_clock::now();
      insercao->ordenar(vetor, 0, tamanhos[i]-1, mAtual);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);       

      string1 << "Tempo na execucao " << j+1 << " com m= "<< mAtual <<" e vetor tam = " << tamanhos[i] << " : "<< duration.count() << " microsegundos" << endl;
      string2 << "Comparacoes feitas: " << insercao->getComparacoes() << endl;
      string3 << "Trocas feitas: " << insercao->getTrocas() << endl << endl;
      
      delete insercao;
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