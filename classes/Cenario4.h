#ifndef CENARIO4_H
#define CENARIO4_H
using namespace std;
#include <iostream>
#include <fstream>


class Cenario4
{
private:
int n;

public:
  Cenario4(); 
  ~Cenario4();    
  void sondagemLinear();
  void sondagemquadratica();
  void duploHash();
  void encadeamentoSeparado();
  void encadeamentoCoalescido();
};

#endif // CENARIO4_H