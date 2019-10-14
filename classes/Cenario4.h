#ifndef CENARIO4_H
#define CENARIO4_H
using namespace std;
#include <iostream>
#include <fstream>


class Cenario4
{
private:
int tamanhos[6];

public:
  Cenario4(); 
  ~Cenario4();    
  void sondagemLinear();
  void sondagemQuadratica();
  void duploHash();
  void encadeamentoSeparado();
  void encadeamentoCoalescido();
};

#endif // CENARIO4_H