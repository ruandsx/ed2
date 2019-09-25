#include <iostream>
#include <vector>
#include <stdlib.h>


using std::vector;
using std::cout;
using std::endl;


class Quicksort {
 private:

    /**
     * Vetor de inteiros a ser ordenado
     */
    vector<int>& elements;

    /**
     * Tamanho do vetor
     */
    int size;

    /**
     * Método de particionamento que é o núcleo do algoritmo Quicksort.
     * É a implementação utilizando o paradigma dividir para conquistar
     */

    int medianaX(int high)
    {

      int a = rand() % high;

      int b = rand() % high;

      int c = rand() % high;

      int vetor[3];
      vetor[0] = elements[a];
      vetor[1] = elements[b];
      vetor[2] = elements[c];
      int tamanho = 3;

        int med, max, min;
        min = 0;
        med = 0;
        max = 0;

        for(int i=0; i< tamanho-1;i++){
            if(vetor[i]<vetor[min]){
                min = i;
            }
            if(vetor[i]>vetor[max]){
                max = i;
            }
        }
        for(int i=0; i< tamanho-1;i++){
            if(vetor[i]>vetor[min] && vetor[i]<vetor[max]){
                med = i;
            }
        }

    
          return med;

    }


    int partition (const int start, const int end)
    {
        int i = medianaX(end);

        for (int j = i; j < end; j++) {

            /*  Elemento atual menor ou igual ao pivô? */
            if (elements[j] <= elements[end]) {
                swap(i++, j);
            }
        }
        swap(i, end);

        return i;
    }

    /**
     * Método para fazer a troca de dados entre duas posições no vetor
     */
    void swap (const int i, const int j)
    {
        int k = elements[i];
        elements[i] = elements[j];
        elements[j] = k;
    }

    /**
     * Método privado que implementa o Quicksort recursivamente
     */
    void quicksort (const int start, const int end)
    {
        snapshot();

        if (start >= end) return;

        int pivot = partition(start, end);

        quicksort(start, pivot - 1);
        quicksort(pivot + 1, end);
    }

    /**
     * Método utilizado para debugging. Imprime na tela uma 'foto' do vetor
     */
    void snapshot ()
    {
        cout << "[";
        for(auto i = elements.begin(); i < elements.end() - 1; i++) {
            cout << *i << ", ";
        }
        cout << elements.back() << "]" << endl;
    }

 public:
    explicit Quicksort (vector<int>& elements)
    :elements(elements),
     size(elements.size())
    {
    }

    /**
     * Método publico que executa a ordenação
     */
    void Sort ()
    {
        if(size <= 1) return;

        quicksort(0, size - 1);
        snapshot();
    }
};


int
main (int argc, char* argv[])
{
    vector<int> elements = {46, 34, 75, 25, 83, 43, 77, 21, 92, 83, 89, 30, 91, 21, 83, 69, 13, 26, 30, 7, 34, 39, 17, 3, 97, 33, 43, 44, 97, 3, 39, 57, 99, 49, 3, 45, 62, 54, 96, 55, 87, 46, 42, 38, 81, 36, 12, 40, 49, 15, 69, 59, 63, 54, 97, 62, 44, 9, 7, 49, 86, 19, 79, 52, 25, 29, 24, 53, 82, 51, 43, 74, 22, 97, 28, 43, 37, 96, 99, 89, 90, 88, 47, 13, 86, 35, 28, 24, 61, 59, 80, 97, 65, 88, 63, 86, 6, 4, 48, 14, 46, 34, 75, 25, 83, 43, 77, 21, 92, 83, 89, 30, 91, 21, 83, 69, 13, 26, 30, 7, 34, 39, 17, 3, 97, 33, 43, 44, 97, 3, 39, 57, 99, 49, 3, 45, 62, 54, 96, 55, 87, 46, 42, 38, 81, 36, 12, 40, 49, 15, 69, 59, 63, 54, 97, 62, 44, 9, 7, 49, 86, 19, 79, 52, 25, 29, 24, 53, 82, 51, 43, 74, 22, 97, 28, 43, 37, 96, 99, 89, 90, 88, 47, 13, 86, 35, 28, 24, 61, 59, 80, 97, 65, 88, 63, 86, 6, 4, 48, 14, 46, 34, 75, 25, 83, 43, 77, 21, 92, 83, 89, 30, 91, 21, 83, 69, 13, 26, 30, 7, 34, 39, 17, 3, 97, 33, 43, 44, 97, 3, 39, 57, 99, 49, 3, 45, 62, 54, 96, 55, 87, 46, 42, 38, 81, 36, 12, 40, 49, 15, 69, 59, 63, 54, 97, 62, 44, 9, 7, 49, 86, 19, 79, 52, 25, 29, 24, 53, 82, 51, 43, 74, 22, 97, 28, 43, 37, 96, 99, 89, 90, 88, 47, 13, 86, 35, 28, 24, 61, 59, 80, 97, 65, 88, 63, 86, 6, 4, 48, 14, 46, 34, 75, 25, 83, 43, 77, 21, 92, 83, 89, 30, 91, 21, 83, 69, 13, 26, 30, 7, 34, 39, 17, 3, 97, 33, 43, 44, 97, 3, 39, 57, 99, 49, 3, 45, 62, 54, 96, 55, 87, 46, 42, 38, 81, 36, 12, 40, 49, 15, 69, 59, 63, 54, 97, 62, 44, 9, 7, 49, 86, 19, 79, 52, 25, 29, 24, 53, 82, 51, 43, 74, 22, 97, 28, 43, 37, 96, 99, 89, 90, 88, 47, 13, 86, 35, 28, 24, 61, 59, 80, 97, 65, 88, 63, 86, 6, 4, 48, 14, 46, 34, 75, 25, 83, 43, 77, 21, 92, 83, 89, 30, 91, 21, 83, 69, 13, 26, 30, 7, 34, 39, 17, 3, 97, 33, 43, 44, 97, 3, 39, 57, 99, 49, 3, 45, 62, 54, 96, 55, 87, 46, 42, 38, 81, 36, 12, 40, 49, 15, 69, 59, 63, 54, 97, 62, 44, 9, 7, 49, 86, 19, 79, 52, 25, 29, 24, 53, 82, 51, 43, 74, 22, 97, 28, 43, 37, 96, 99, 89, 90, 88, 47, 13, 86, 35, 28, 24, 61, 59, 80, 97, 65, 88, 63, 86, 6, 4, 48, 14 , 46, 34, 75, 25, 83, 43, 77, 21, 92, 83, 89, 30, 91, 21, 83, 69, 13, 26, 30, 7, 34, 39, 17, 3, 97, 33, 43, 44, 97, 3, 39, 57, 99, 49, 3, 45, 62, 54, 96, 55, 87, 46, 42, 38, 81, 36, 12, 40, 49, 15, 69, 59, 63, 54, 97, 62, 44, 9, 7, 49, 86, 19, 79, 52, 25, 29, 24, 53, 82, 51, 43, 74, 22, 97, 28, 43, 37, 96, 99, 89, 90, 88, 47, 13, 86, 35, 28, 24, 61, 59, 80, 97, 65, 88, 63, 86, 6, 4, 48, 14};

    Quicksort sort(elements);
    sort.Sort();

    return 0;
}