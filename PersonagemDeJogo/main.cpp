#include <string>
#include <iostream>

#include "personagem.h"

int main() {
    Personagem p1;
    p1.nome = "Kratos";
    p1.tipo = TipoPersonagem::Guerreiro;
    p1.vidas = 100;
    p1.forca = 20;

    Personagem p2;
    p2.nome = "Willow";
    p2.tipo = TipoPersonagem::Mago;
    p2.vidas = 80;
    p2.forca = 25;

    Personagem p3;
    p3.nome = "Merida";
    p3.tipo = TipoPersonagem::Arqueiro;
    p3.vidas = 90;
    p3.forca = 15;

    p1.exibirStatus();
    p2.exibirStatus();
    p3.exibirStatus();

    std::cout << "\n=== Luta ===\n" << std::endl;

    std::cout << "\n--- Round 1 ---\n" << std::endl;
    p2.ataque();
    p3.receberDano(p2.forca);

    std::cout << "\n--- Round 2 ---\n" << std::endl;
    p3.ataque();
    p2.receberDano(p3.forca);

    std::cout << "\n--- Round 3 ---\n" << std::endl;
    p3.ataque();
    p2.receberDano(p3.forca);

    std::cout << "\n=== Fim da luta ===\n" << std::endl;
    if(p2.getVidas() < p3.getVidas()) {
        std::cout << p3.nome << " venceu a luta!" << std::endl;
    } else if(p2.getVidas() > p3.getVidas()) {
        std::cout << p2.nome << " venceu a luta!" << std::endl;
    } else {
        std::cout << "A luta terminou em empate!" << std::endl;
    }

    return 0;
}
