#ifndef QUICKSORTMEDIANA_H
#define QUICKSORTMEDIANA_H
using namespace std;


class QuicksortMediana
{
private:
unsigned long int comparacoes;
unsigned long int trocas;
int medianaTresOuCinco;

public:
  QuicksortMediana(int tipo); 
  ~QuicksortMediana();    
  void ordenar(int arr[], int low, int high);
  int particionar(int arr[], int low, int high);
  int mediana3(int *V, int low, int high);
  int mediana5(int *V, int low, int high);
  void trocar(int* a, int* b);
  int getTrocas();
  int getComparacoes();

};

#endif // QUICKSORTMEDIANA_H