#include <iostream>
#include <string>
#include <list> 
#include <time.h>

#include "../classes/hashTable.h"
#define PRIMO 13

using namespace std;

hashTable::hashTable(int tamanho){
    this->tamanho = tamanho;
    tabela = new int [tamanho];
    tamanho_atual = 0;
    comparacoes = 0;
}

int hashTable :: fHashing(int x){
    return x%tamanho;
}
int hashTable:: f2Hashing(int x){
    return (PRIMO - (x % PRIMO));
}

void hashTable::criaTabela(){
    for (int i = 0; i < tamanho; i++)
        tabela[i] = -1 ;
}

void hashTable::doubleHashing(int x){
    int index  = fHashing(x);

    if(tabela[index] != -1)
    {
        int index2 = f2Hashing(x);
        comparacoes++;
        int i = 1;

        while (true)
        {
            int newIndex = (index + i * index2)% tamanho; //Faz o novo índice onde será alocado o valor X  

            if(tabela[newIndex] == -1)
            {
               tabela[newIndex] = x;   // se o novo indice funcionar insere o valor x
               tamanho_atual++;
               break;
            } 
            //If para retornar ao inicio da tabela
            //Se o indice for maior que o tamanho da tabela ele faz Indice - TamanhoTabela
            if (newIndex > tamanho)
                newIndex = newIndex - tamanho;   
           i++;
        }
    }
    else
        tabela[index] = x; //Se nao houver colisão ele apenas insere na posicao 
        tamanho_atual++;
}
//pos = posicao ocupada que tentaram inserir x || i = indice da tentativa de vezes
int hashTable::sLinearindex(int pos, int i){
    return (pos + i) % tamanho;
}

void hashTable::sondagemLinear(int x){
    int index = fHashing(x);
    if (tabela[index] == -1){
        tabela[index] = x;
        tamanho_atual++;
    }

    else
    { 
        int i = 0;
        int novoIndice;
        while (true)
        {
            novoIndice = sLinearindex(index,i);
            comparacoes++;
            if(tabela[novoIndice] == -1){
                tabela[index] = x;
                tamanho_atual++;
                break;
            }
            i++;

            if (novoIndice > tamanho){
                novoIndice = 0;
                i = 0;
            }
                
        } 
    }
}
int hashTable::sQuadraticaindex(int pos, int i){
    pos = pos + (i*i);
    return pos % tamanho;
}

void hashTable::sondagemQuadratica(int x){
    int index = fHashing(x);
    if (tabela[index] == -1){
        tabela[index] = x;
        tamanho_atual++;
    }
    else
    {
        int i = 0;
        int novoIndice;
        while (true)
        {
            novoIndice = sQuadraticaindex(index,i);
            comparacoes++;
            if (tabela[novoIndice] == -1)
            {
                tabela[novoIndice] = x;
                tamanho_atual++;
                break;
            }
            i++;

            if(novoIndice > tamanho){
                novoIndice = 0;
                i = 0;
            }
        }
    }
}

void hashTable::imprimeTabela(){
    for (int i = 0; i < tamanho; i++)
        cout<<i<<" -> "<<tabela[i]<<endl;
}

int hashTable::getMemoria(){
    return tamanho_atual * 4;
}

int hashTable::getComparacoes(){
    return comparacoes;
}