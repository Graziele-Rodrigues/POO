
#include <iostream>
#include <string>
#include "pet.h"

void PetVirtual::cadastrarPet() {
    std::cout << "Digite o nome do pet: ";
    std::cin >> nome;
    std::cout << "Digite o nivel de fome do pet (0-100): ";
    std::cin >> fome;
    std::cout << "Digite o nivel de felicidade do pet (0-100): ";
    std::cin >> felicidade;
}

void PetVirtual::mostrarStatus() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Fome: " << fome << std::endl;
    std::cout << "Felicidade: " << felicidade << std::endl;
}

void PetVirtual::alimentar() {
    fome -= 10;
    if (fome < 0) fome = 0;
    if (fome > 80) {
        felicidade -= 50;
        if (felicidade < 0) felicidade = 0;
    }
    std::cout << nome << " foi alimentado!" << std::endl;
}

void PetVirtual::brincar() {
    felicidade += 10;
    if (felicidade > 100) felicidade = 100;
    if (felicidade < 40) std::cout << "O pet esta triste! Alimente ou Brinque com ele..." << std::endl;
    else std::cout << nome << " esta feliz!" << std::endl;
}
