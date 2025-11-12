#include <string>
#include <iostream>
#include "personagem.h"

void Personagem::ataque() {
    std::cout << nome << " do tipo " << tipoToString() << " atacou com força " << forca << "!" << std::endl;
}

void Personagem::receberDano(int dano) {
    vidas -= dano;
    if (vidas < 0) vidas = 0;
    std::cout << nome << " recebeu " << dano << " de dano. Vidas restantes: " << vidas << std::endl;
}

void Personagem::exibirStatus() {
    std::cout << "Nome: " << nome << ", Tipo: " << tipoToString() << ", Vidas: " << vidas << std::endl;
}

int Personagem::getVidas() {
    return vidas;
}

std::string Personagem::tipoToString() {
    switch (tipo) {
        case TipoPersonagem::Guerreiro: return "Guerreiro";
        case TipoPersonagem::Mago: return "Mago";
        case TipoPersonagem::Arqueiro: return "Arqueiro";
        default: return "Desconhecido";
    }
}