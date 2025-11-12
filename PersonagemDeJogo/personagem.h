#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <iostream>

enum class TipoPersonagem {
    Guerreiro,
    Mago,
    Arqueiro
};

class Personagem {
public:
    std::string nome;
    TipoPersonagem tipo;
    int vidas;
    int forca;

    void ataque();
    void receberDano(int dano);
    void exibirStatus();
    int getVidas();
    std::string tipoToString();
};

#endif