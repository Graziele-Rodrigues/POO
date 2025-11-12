#ifndef PET_VIRTUAL_H
#define PET_VIRTUAL_H
#include <iostream>
#include <string>

class PetVirtual {
public:
    std::string nome;
    int fome;
    int felicidade;

    void cadastrarPet();
    void mostrarStatus();
    void alimentar();
    void brincar();
};

#endif