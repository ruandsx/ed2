#ifndef CENARIO1_H
#define CENARIO1_H
using namespace std;
#include <iostream>
#include <fstream>


class Cenario1
{
private:
int n;

ifstream leitor;
ofstream gravador;

public:
  Cenario1(); 
  ~Cenario1();    
  void lerArquivo();
  void gravarArquivo();
  void criaVetor();
  void ordenar();
};

#endif // CENARIO1_H