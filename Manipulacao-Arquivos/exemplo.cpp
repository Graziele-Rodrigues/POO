#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int escritaArquivo(){
    ofstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/dados.txt");

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    arquivo << "Linha 1: Dados de exemplo" << endl;
    arquivo << "Linha 2: Mais dados de exemplo" << endl;

    arquivo.close();
    cout <<"Arquivo escrito com sucesso!" << endl;
    return 0;
};

int leituraArquivo(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/dados.txt");
    string linha;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while(getline(arquivo, linha)){
        cout << linha << endl; // mostra a linha lida
    }

    arquivo.close();
    return 0;
};

int leituraNUmeros(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/numeros.txt");
    int numero, soma = 0;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
  
    while(arquivo >> numero){
        soma += numero;
    }

    arquivo.close();
    cout << "Soma dos números: " << soma << endl;
    return 0;
}


int leituraPalavra(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/palavras.txt");
    string palavra, maiorPalavra;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while(arquivo >> palavra){
        std::cout << "Palavra lida: " << palavra << endl;
    }

    arquivo.close();

    return 0;
}

int leituraComDelimitador(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/dados_delimitados.txt");
    string linha;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    getline(arquivo, linha, ';');
    getline(arquivo, linha, ';');
    getline(arquivo, linha, ';');
    getline(arquivo, linha, ';');

    arquivo.close();
    return 0;
}

int voltandoLinha(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/dados.txt");
    string linha;
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while(getline(arquivo, linha)){
        cout << linha << endl;
    }
    arquivo.clear();
    arquivo.seekg(0, ios::beg);

    arquivo.close();
    return 0;
}


int main(){
    escritaArquivo();
    leituraArquivo();
    leituraNUmeros();
    leituraPalavra();
    leituraComDelimitador();
    voltandoLinha();
    return 0;
}