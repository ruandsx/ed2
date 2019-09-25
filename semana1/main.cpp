#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void criarArquivo(){

}

int main()
{
    string str, nome;
    ifstream arquivoR;
    ofstream arquivoW;
    int matricula;
    float nota1, nota2;

    arquivoR.open("alunos.txt");
    arquivoW.open("alunos.txt");

    arquivoW << "2, Maria da Silva, 8.5, 4.8," << endl;
    arquivoW << "13, Joao de Almeida, 7.5, 6.1," << endl;
    arquivoW << "15, Pedro de Souza, 5.0, 4.4," << endl;
    arquivoW << "21, Jose de Carvalho, 7.2, 7.1," << endl;
    arquivoW << "30, Silvia Santos, 5.9, 6.2," << endl;
    arquivoW.close();

    while(!arquivoR.eof()){
        getline(arquivoR,str, ',');
        cout << "Matricula: ";
        cout << str << endl;
        getline(arquivoR,str, ',');
        cout << "Nome: ";
        cout << str << endl;
        getline(arquivoR,str, ',');
        nota1 = atof(str.c_str());
        getline(arquivoR,str, ',');
        nota2 = atof(str.c_str());
        cout << "Media: " << (nota1+nota2)/2 << endl;
        cout << "" << endl;
        getline(arquivoR, str, '\n');
    }
    arquivoR.close();

    cout << "Digite a Matricula: ";
    cin >> matricula ;
    cout << "Digite o Nome: ";
    getline(cin, nome);
    cout << "Digite a nota 1: ";
    cin >> nota1 ;
    cout << "Digite a nota 2: ";
    cin >> nota2 ;

    arquivoW.open("alunos.txt", std::ios_base::app);
    arquivoW << matricula << ", " << nome << ", " << nota1 << ", " << nota2 << ", ";
    arquivoW.close();

    return 0;
}
