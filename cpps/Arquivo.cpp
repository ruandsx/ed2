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
        cout << "Arquivo Aberto com sucesso, tipo: leitura" << endl;
      }
  }else{
      gravador.open(caminho, ofstream::app);

      if(!gravador.is_open()){
      cout << "Nao foi possivel abrir o arquivo em " << caminho << endl;
      }else{
        cout << "Arquivo Aberto com sucesso, tipo: escrita" << endl;
      }
  }
    
}

void Arquivo::ler(){
    string dados;
    getline(leitor, dados);
    cout << dados ;
}

void Arquivo::gravar(string dados){
    gravador << dados;
}

void Arquivo::fechar(){
    leitor.close();
    gravador.close();
}
