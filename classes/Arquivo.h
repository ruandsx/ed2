#ifndef ARQUIVO_H
#define ARQUIVO_H
using namespace std;
#include <iostream>
#include <fstream>
#include <string>


class Arquivo
{
private:
int n;

ifstream leitor;
ofstream gravador;

public:
  Arquivo(); 
  ~Arquivo();   
  void abrir(string caminho, char operacao); 
  void getTamanhos(int tamanhos[]);
  void montarVetor(int vetor[], int tam);
  void gravar(string dados);
  void fechar();
};

#endif // ARQUIVO_H