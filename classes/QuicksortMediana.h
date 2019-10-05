#ifndef QUICKSORTMEDIANA_H
#define QUICKSORTMEDIANA_H
using namespace std;


class QuicksortMediana
{
private:
int comparacoes;
int trocas;

public:
  QuicksortMediana(); 
  ~QuicksortMediana();    
  void ordenar(int arr[], int low, int high);
  int particionar(int arr[], int low, int high);
  int mediana(int *V, int low, int high);
  void trocar(int* a, int* b);
  int getTrocas();
  int getComparacoes();

};

#endif // QUICKSORTMEDIANA_H