#include <iostream>
#include <string>

#include "diario.h"

int main() {
    Diario meuDiario;
    std::cout << "Qual o seu nome?" << std::endl;
    std::getline(std::cin, meuDiario.nomeDono);
    std::cout << "Defina uma senha para o seu diario:" << std::endl;
    std::getline(std::cin, meuDiario.senha);

    std::string senhaInput;
    std::string textoInput;

    while(1){
        int opcao;
        std::cout << "Escolha uma opcao:\n1. Escrever no diario\n2. Ler o diario\n3. Sair\n";
        std::cin >> opcao;
        std::cin.ignore(); // Limpar o buffer do cin
        if(opcao == 1){
            std::cout << "Digite a senha para escrever no diario: ";
            std::cin >> senhaInput;
            std::cin.ignore(); // Limpar o buffer do cin
            std::cout << "Digite o texto para o diario: ";
            std::getline(std::cin, textoInput);
            meuDiario.escrever(textoInput, senhaInput);
        } else if(opcao == 2){
            std::cout << "Digite a senha para ler o diario: ";
            std::cin >> senhaInput;
            meuDiario.ler(senhaInput);
        } else if(opcao == 3){
            return 0;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }

    return 0;
}