// pedir ao usuario uma palavra e verificar se ela existe no arquivo 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream arquivo("D:/Projetos/POO/Manipulacao-Arquivos/arquivos/exercicio3.txt");
    string palavraArquivo, palavraUsuario;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    cout << "Adivinhe uma palavra que existe no arquivo: " << endl;
    cout << "DICA: Musica Milton Nascimento" << endl;
    cin >> palavraUsuario;

    while(arquivo >> palavraArquivo){
        if(palavraArquivo == palavraUsuario){
            cout << "Parabens! Voce acertou a palavra: " << palavraUsuario << endl;
            arquivo.close();
            return 0;
        }
    }
    cout << "Que pena! A palavra " << palavraUsuario << " nao existe no arquivo." << endl;
    arquivo.close();
}