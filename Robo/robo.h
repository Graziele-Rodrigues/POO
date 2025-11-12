#ifndef ROBO_H
#define ROBO_H

#include <string>

class Robo {
public:
    std::string nome;
    int energia;

    void executarTarefa();
    void recarregar();
    void mostrarStatus();
};

#endif