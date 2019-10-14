#include <iostream>
#include <string>
#include <list> 
#define PRIMO 13


using namespace std;

class hashTable{
    private: 
        int tamanho; //tamanho inicial da tabela
        int tamanho_atual = 0; //tamanho enquanto vai inserindo os trem
        int comparacoes = 0;
        int *tabela; // tabela Hashing

    public:
        hashTable(int tamanho);
        //Função Hashing: determina o índice em que o valor x da tabela vai ser inserido no vetor a
        // partir do resto da sua divisao pelo tamanho n da amostra
        int fHashing(int x);
        void criaTabela();
        int f2Hashing(int x);
        void doubleHashing(int x);
        //insere o valor x na tabela Hashing por endereçamento separado
        void endSeparado(int x);
        //retorna o îndice onde o valor x deve ser inserido
        void sondagemLinear(int x);
        int sLinearindex(int pos, int i);
        // retorna o îndice onde o valor x deve ser inserido
        int sQuadraticaindex(int pos, int i);
        void sondagemQuadratica(int x);
        //função para imprimir a tabela 
        void imprimeTabela();
        int getMemoria();
        int getComparacoes();

};