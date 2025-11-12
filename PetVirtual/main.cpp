#include <iostream>
#include <string>
#include "pet.h"

int main() {
    PetVirtual pet;
    pet.cadastrarPet();

    while(1) {
        int escolha = 0;
        std::cout << "\nMenu:\n1. Mostrar Status\n2. Alimentar Pet\n3. Brincar com Pet\n4. Sair\nEscolha uma opcao: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                pet.mostrarStatus();
                break;
            case 2: {
                pet.alimentar();
                break;
            }
            case 3:
                pet.brincar();
                break;
            case 4:
                std::cout << "Saindo do programa." << std::endl;
                return 0;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
    return 0;
}