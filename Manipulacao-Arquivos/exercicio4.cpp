// mostrar maior e menor valor em um arquivo de numeros

#include <iostream>
#include <fstream>

using namespace std;

int gerarArquivoNumeros() {
    ofstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio4.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita" << endl;
        return 1;
    }

    for (int i = 0; i < 50; ++i) {
        arquivo << rand() % 1000 << endl; // números aleatórios entre 0 e 999
    }

    arquivo.close();
    return 0;
}

int encontrarMaiorMenor() {
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio4.txt");
    int numero = 0, maior=0, menor=1000;

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura" << endl;
        return 1;
    }

    while (arquivo >> numero) {
        if (numero > maior) {
            maior = numero;
        }
        if (numero < menor) {
            menor = numero;
        }
    }

    arquivo.close();

    cout << "Maior numero: " << maior << endl;
    cout << "Menor numero: " << menor << endl;

    return 0;
}

int main() {
    gerarArquivoNumeros();
    encontrarMaiorMenor();
    return 0;
}