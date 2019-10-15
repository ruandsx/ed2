#include <stdio.h>
#include "../classes/endCoalescido.h"

using namespace std;

endCoalescido::~endCoalescido(){

    delete [] tabela;
    delete [] colisoes;

}

endCoalescido::endCoalescido(unsigned numkeys)
{
    this->numeroChaves = numkeys;

    this->tabela = new unsigned[numkeys];
    this->colisoes = new unsigned[numkeys];

    for(int i = 0; i < numkeys; i++){
        this->tabela[i] = -1;
        this->colisoes[i] = -1; 
    }
    

}

unsigned endCoalescido::getIndiceColisao(unsigned index){


    int proxColisao = this->colisoes[index];

    for(; this->colisoes[proxColisao] == -1; proxColisao = this->colisoes[proxColisao]);

    return proxColisao;
}

unsigned endCoalescido::funcaoHash(unsigned chave)
{
    return (chave % this->numeroChaves);
}



void endCoalescido::insereItem(unsigned key, unsigned *contaColisoes)
{
    
    unsigned index = funcaoHash(key);

    if(this->tabela[index] == -1) 
        this->tabela[index] = key;

    else{

        (*contaColisoes)++;

        if(this->colisoes[index] == -1){

            
            for(int i = this->numeroChaves; i >= 0; i--) 
                
                if(this->tabela[i] == -1){ 

                    this->tabela[i] = key;
                    
                    this->colisoes[index] = i;
                
                }

        }else{ 

            
            for(int i = this->numeroChaves; i >= 0; i--) 
                if(this->tabela[i] == -1){ 

                    this->tabela[i] = key;

                    unsigned indexColision = this->getIndiceColisao(index);

                    this->colisoes[indexColision] = i;
           
                }

        }

    }

}