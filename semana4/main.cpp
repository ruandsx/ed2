//Desenvolva algoritmos de ordenação passados na aula dessa semana para ordenar o campo #id do arquivo 2019-05-02.csv
//Obs: conforme terão que fazer para o trabalho, faça a leitura de linhas aleatórias do arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


  
 
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
 
        if (arr[j] <= pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

  

void swapping(int &a, int &b) {     
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

int main()
{
    string id;
    ifstream arquivoR;
    int valor, aux=0;
    vector <int> ids;

    arquivoR.open("2019-05-02.csv");
    int cont =0;
    while(!arquivoR.eof()){
        getline(arquivoR,id, ',');
        //cout << "ID: ";
        //cout << id << endl;
        valor = atof(id.c_str());
        ids.push_back(valor);
        int v2 = rand() % 100 + 1;
        for(int i=0; i<= v2; i++){
            getline(arquivoR, id);
        }
        //getline(arquivoR, id);
        cont++;
    }

    arquivoR.close();
    int vetorQ[cont];
    int vetorM[cont];

    for(int i=0; i< cont; i++){
        vetorQ[i] = ids[i];
    }
    for(int i=0; i< cont; i++){
        vetorM[i] = ids[i];
    }
  
    quickSort(vetorQ, 0, cont-1);  
    mergeSort(vetorM, 0, cont-1);

    for(int i=0; i< cont; i++){
        cout<< "Ordenado pelo ID e pelo Quicksort: " << vetorQ[i] << endl;
    }
    for(int i=0; i< cont; i++){
        cout<< "Ordenado pelo ID e pelo Mergesort: " << vetorM[i] << endl;
    }



    return 0;
}