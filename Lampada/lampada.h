#ifndef LAMPADA_H
#define LAMPADA_H

#include <string>

class Lampada {
public:
    bool ligada;
    std::string cor;

    void ligar();
    void desligar();
    void mostrarEstado();
    void trocarCor(std::string novaCor);
};

#endif