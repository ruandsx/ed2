#ifndef ENDCOALESCIDO_H
#define ENDCOALESCIDO_H
#include <stdio.h>

using namespace std;

class endCoalescido
{
    private:
        unsigned numeroChaves;
        unsigned* tabela;
        unsigned* colisoes;
        unsigned tamanho;


    public:
        endCoalescido(unsigned numeroChaves);
        ~endCoalescido();
        unsigned getIndiceColisao(unsigned indice);
        unsigned funcaoHash(unsigned chave);
        void insereItem(unsigned chave, unsigned *countColisoes);
        
};


#endif // ENDCOALESCIDO_H
