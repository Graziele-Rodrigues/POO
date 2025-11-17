// contar quantas palavras tem um arquivo de texto

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int escritaArquivo(){
    ofstream arquivo ("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio2.txt");

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    for(int i = 1; i <= 20; i++){
        arquivo << "Palavra" << i << " ";
    }

    arquivo.close();
    cout <<"Arquivo escrito com sucesso!" << endl;
    return 0;
}

int contarPalavras(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio2.txt");
    string palavra;
    int contador = 0;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while(arquivo >> palavra){
        contador++;
    }

    arquivo.close();
    cout << "O arquivo possui " << contador << " palavras." << endl;
    return 0;
}

int main(){
    escritaArquivo();
    contarPalavras();
    return 0;
}