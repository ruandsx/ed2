#include "../classes/Cenario1.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;


Cenario1::Cenario1(){
}

Cenario1::~Cenario1(){
}

void Cenario1::lerArquivo(){
    int quantidadeTestes = 0;
    string lido;
    leitor.open("../assets/entrada.txt");

    getline(leitor, lido, '\n');
    quantidadeTestes = atof(lido.c_str());

    int ns[quantidadeTestes];
    for(int i=0; i<quantidadeTestes; i++)
    {
        getline(leitor, lido);
        ns[i] = atof(lido.c_str());
    }
    for(int i=0; i<quantidadeTestes; i++){
        cout << ns[i] << endl;
    }

    leitor.close();
}

void Cenario1::gravarArquivo(){

}

void Cenario1::criaVetor(){

}

void Cenario1::ordenar(){

}