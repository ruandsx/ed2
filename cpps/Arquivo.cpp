#include "../classes/Arquivo.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;


Arquivo::Arquivo(){
}

Arquivo::~Arquivo(){
}

void Arquivo::abrir(string caminho, char operacao){
  if(operacao=='l'){
      leitor.open(caminho);

      if(!leitor.is_open()){
        cout << "Nao foi possivel abrir o arquivo em " << caminho << endl;
      }else{
        //cout << "Arquivo Aberto com sucesso, tipo: leitura" << endl;
      }
  }else{
      gravador.open(caminho, ofstream::app);

      if(!gravador.is_open()){
        cout << "Nao foi possivel abrir o arquivo em " << caminho << endl;
      }else{
        //cout << "Arquivo Aberto com sucesso, tipo: escrita" << endl;
      }
  }
    
}


void Arquivo::getTamanhos(int tamanhos[]){
    string dados;
    getline(leitor,dados);
    tamanhos[0] = atof(dados.c_str());

    for(int i=1; i<=tamanhos[0]; i++)
    {
        getline(leitor, dados);
        tamanhos[i] = atof(dados.c_str());
    }
}

void Arquivo::montarVetor(int vetor[], int tam){
    int i=0, id, linha;
    string dados;

    while(i<tam)
    {
        getline(leitor,dados, ',');
        id = atof(dados.c_str());
        vetor[i] = id;

        linha = rand() % (13000000/tam) + 0;
        for(int i=0; i<=linha;i++){
            getline(leitor, dados);
        }

        getline(leitor, dados);
        i++;
    }

  //  for(int i=0; i<10; i++){
  //    cout<<vetor[i]<<" ";
  //  }
    cout<<endl;
}

void Arquivo::gravar(string dados){
    gravador << dados;
}

void Arquivo::fechar(){
    leitor.close();
    gravador.close();
}
