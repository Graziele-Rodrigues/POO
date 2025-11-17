// contar e mostrar quantas linhas tem um arquivo de texto

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int escritaArquivo(){
    ofstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio1.txt");

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    for(int i = 1; i <= 50; i++){
        arquivo << "Esta é a linha número " << i << endl;
    }

    arquivo.close();
    cout <<"Arquivo escrito com sucesso!" << endl;
    return 0;
};


int contarLinhas(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio1.txt");
    string linha;
    int contador = 0;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while(getline(arquivo, linha)){
        contador++;
    }

    arquivo.close();
    cout << "O arquivo possui " << contador << " linhas." << endl;
    return 0;
}


int main(){
    escritaArquivo();
    contarLinhas();
    return 0;
}