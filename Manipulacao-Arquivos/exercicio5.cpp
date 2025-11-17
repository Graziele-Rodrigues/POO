// mudar todas ocorrencias de palavra "cachorro" para "mingau"  

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
// Deixa tudo na mesma linha 
void substituirPalavra(string diretorio, string palavraAntiga, string palavraNova) {
    ifstream arquivoEntrada(diretorio);
    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return;
    }

    string conteudo, palavra;

    while (arquivoEntrada >> palavra) {
        if (palavra == palavraAntiga) {
            palavra = palavraNova;
        }
        conteudo += palavra + " ";
    }
    arquivoEntrada.close();

    ofstream arquivoSaida(diretorio);
    if (!arquivoSaida.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    arquivoSaida << conteudo;
    arquivoSaida.close();
}*/

void substituirPalavra(string diretorio, string palavraAntiga, string palavraNova) {
    ifstream arquivoEntrada(diretorio);
    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return;
    }

    string conteudo, linha;
    
    while (getline(arquivoEntrada, linha)) {
        size_t pos = 0;
        while ((pos = linha.find(palavraAntiga, pos)) != string::npos) { // find procura a palavra na linha, npos eh o valor retornado quando nao encontra
            linha.replace(pos, palavraAntiga.length(), palavraNova); // replace substitui a palavra na linha pela nova usando a posicao e o tamanho da palavra antiga
            pos += palavraNova.length(); // avança a posição para continuar a busca após a palavra substituída
        }
        conteudo += linha + "\n"; // coloca quebra de linha apos cada linha lida
    }
    arquivoEntrada.close();

    ofstream arquivoSaida(diretorio); // abre o arquivo para escrita
    if (!arquivoSaida.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    arquivoSaida << conteudo; // escreve o conteudo modificado no arquivo
    arquivoSaida.close();
}

void substituirCachorroPorMingau(string diretorio) {
    substituirPalavra(diretorio, "cachorro", "mingau");
}

void substituirMingauPorCachorro(string diretorio) {
    substituirPalavra(diretorio, "mingau", "cachorro");
}

int main() {
    string diretorio = "D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio5.txt";

    substituirCachorroPorMingau(diretorio);
    cout << "Concluido 1" << endl;

    // substituirMingauPorCachorro(diretorio);
    // cout << "Concluido 2" << endl;

    return 0;
}
