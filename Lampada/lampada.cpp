#include "lampada.h"
#include <iostream>
#include <string>


void Lampada::ligar() {
    ligada = true;
}

void Lampada::desligar() {
    ligada = false;
}

void Lampada::mostrarEstado() {
    std::cout << "A lampada esta " << (ligada ? "ligada" : "desligada") << std::endl;
}

void Lampada::trocarCor(std::string novaCor) {
    if(ligada==false){
        std::cout << "A lampada precisa estar ligada para trocar a cor." << std::endl;
    } else {
        cor = novaCor;
        std::cout << "Cor da lampada trocada para " << novaCor << "." << std::endl;
    }
}