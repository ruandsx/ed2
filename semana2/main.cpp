#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>

//Atividade 2, aula 14/08/2019, Ruan Xavier

using namespace std;

void insertionSort(int x[], int n){
  int i, j, key;  
    for (i = 1; i < n; i++){  
        key = x[i];  
        j = i - 1;  

        while (j >= 0 && x[j] > key){  
            x[j + 1] = x[j];  
            j = j - 1;  
        }  
        x[j + 1] = key;  
    }  
}

void selectionSort(int x[], int n){
  int menor, pos, aux;

    for (int i = 0; i < n; i++){
        menor = x[i];
        pos =i;

        for (int j = i; j < n; j++){
            if (x[j] < menor){
                menor = x[j];
                pos = j;
            }
        }

        aux = x[i];
        x[i] = menor;
        x[pos] = aux;
    }
}

void bubbleSort(int x[], int n){
  int aux;
  for (int i=0; i<n-1 ;i++){
      for(int j=0; j < n-i-1; j++){
        if(x[j]>x[j+1]){
          aux = x[j+1];
          x[j+1] = x[j];
          x[j] = aux;
        }
      }
  }
}

int main(){

  int array1[] = { 1, 10, 5, 4, 8, 3, 9, 6, 2, 7};
  int array2[] = { 1, 10, 5, 4, 8, 3, 9, 6, 2, 7};
  int array3[] = { 1, 10, 5, 4, 8, 3, 9, 6, 2, 7};

  int n = sizeof(array1)/sizeof(array1[0]); 

  cout<< endl << "BubbleSort: ";
  bubbleSort(array1, n);
  for (int i=0; i<n ;i++){
    cout << array1[i] << " ";
  }

  cout<< endl << "SelectionSort: ";
  selectionSort(array2, n);
  for (int i=0; i<n ;i++){
    cout << array2[i] << " ";
  }

  cout<< endl << "InsertionSort: ";
  insertionSort(array3, n);
  for (int i=0; i<n ;i++){
    cout << array3[i] << " ";
  }

  return 0;
}
