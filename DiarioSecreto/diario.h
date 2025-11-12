#ifndef DIARIO_H
#define DIARIO_H

#include <iostream>
#include <string>

class Diario {
public:
    std::string nomeDono;
    std::string texto;
    std::string senha;

    void escrever(std::string texto_digitado, std::string senha_digitada);
    void ler(std::string senha_digitada);
};

#endif