#include<iostream> 
#include <list> 
using namespace std;

class endSeparado{
    private:
        int baldes; // numero de baldes 
        list <int> *tabela; // ponteiro para o array contendo os baldes
        //funcao hashing para retornar o lugar onde a chave deve ser colocada
        //x = valor do elemento ; n = tamanho da tabela Hash
        int hashing(int x, int n){
            return x % n;
        }

    public:
        endSeparado(int v); //construtor
        void insereItem(int x); //insere uma chave na tabela hash
        void imprimeHashing();
};