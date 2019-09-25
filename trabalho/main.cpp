#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std::chrono;
using namespace std;


void snapshot (int arr[], int tam)
{
    cout << "[";
    for(auto i = 0; i < tam-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[tam-1] << "]" << endl;
}


int medianaX(int *V, int low, int high)
{

  int a = 0, b = 0, c = 0;



  a = rand()%(high-low + 1) + low; // gera valores aleatorios entre dois valores (?). Foi o que eu achei na internet
  //cout << "MINIMO: " << low << " MAXIMO: " << high << " VALOR GERADO: " << a << endl;

  b = rand()%(high-low + 1) + low;
  //cout <<" VALOR GERADO: " << b << endl;

  c = rand()%(high-low + 1) + low;
  //cout <<" VALOR GERADO: " << c << endl;

  int vetor[3];
  vetor[0] = V[a];
  //cout <<" VALOR GERADO: " << vetor[0] << endl;
  vetor[1] = V[b];
  //cout <<" VALOR GERADO: " << vetor[1] << endl;
  vetor[2] = V[c];
  //cout <<" VALOR GERADO: " << vetor[2] << endl;

  int tamanho = 3;
  int mediana;
  int aux;

  for(int i=0;i<tamanho-1;i++){
        for(int j=i+1;j<tamanho;j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    mediana = vetor[1];

    for(int i = low; i < high; i++){
        if(V[i] == mediana){
            //cout << "VALOR QUE ESTOU RETORNANDO DO INDICE EH: " << i  << " VALOR ESCOLHIDO PARA MEDIANA EH: " << mediana << endl << endl;
            return i;
        }
    }


    //cout << mediana << endl;
    //return mediana;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high, int * compara, int * troca, int cont)
{
    int pivot, pivito;
    if(high - low > 3)
        pivito = medianaX(arr,low,high);
    else{
      // pivot = arr[high];
        pivito = high;
    }
    pivot = arr[pivito];
    swap(&arr[pivito], &arr[high]);

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            *compara = *compara + 1;
            i++;
            swap(&arr[i], &arr[j]);
            *troca = *troca + 1;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    *troca = *troca + 1;
    return (i + 1);
}


void quickSort(int arr[], int low, int high, int * compara, int * troca, int cont)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, compara, troca, cont);

        quickSort(arr, low, pi - 1, compara, troca, cont);
        quickSort(arr, pi + 1, high, compara, troca, cont);
    }
    *compara = *compara + 1;
}

void imprimeVetor(int v[], int cont)
{
    for(int i=0; i< cont; i++)
    {
        cout<< "Ordenado pelo ID e pelo Quicksort: " << v[i] << endl;
    }
}

void fazTudo(int * compara, int * troca, int * aleatoriedade)
{
    vector <int> ids1;

    string id;
    int valor;


    ifstream arquivoR;
    arquivoR.open("bgg-13m-reviews.csv");

    int cont =0;
    int linha;

    while(cont<=*aleatoriedade)
    {
        getline(arquivoR,id, ',');
        valor = atof(id.c_str());
        ids1.push_back(valor);

        linha = rand() % (13000000/(*aleatoriedade)) + 0;
        for(int i=0; i<=linha;i++){
            getline(arquivoR, id);
        }

        cont++;
    }
    arquivoR.close();

    int vetor1[cont];
    for(int i=0; i< cont; i++)
    {
        vetor1[i] = ids1[i];
    }
    quickSort(vetor1, 0, cont-1, compara, troca, cont);

    snapshot(vetor1, cont);
    cont = 0;
}

int main()
{
  srand(time(NULL));
  cout << fixed << setprecision(3);

    int compara,troca;
    
    int valor;
    string id;


    ifstream arquivoR;
    arquivoR.open("entrada.txt");

    getline(arquivoR,id, '\n');
    valor = atof(id.c_str());
    int ns[valor];

    for(int i=0; i<valor; i++)
    {
        getline(arquivoR, id);
        ns[i] = atof(id.c_str());
    }

    //snapshot(ns, valor);
    arquivoR.close();


    for(int i=0; i<valor; i++)
    {
        
        compara = 0;
        troca = 0;
        auto start = high_resolution_clock::now();
        fazTudo(&compara, &troca, &ns[i]);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Tempo na execucao "<< i+1 << ": "<< duration.count() /float(1000000) << " segundos" << endl;
        cout << "Comparacoes feitas: " << compara << endl;
        cout << "Trocas feitas: " << troca << "\n"<< endl;
    }

    return 0;
}