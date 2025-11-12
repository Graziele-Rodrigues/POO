#include <iostream>
#include <string> 

#include "lampada.h"

int main(){
    Lampada lampada;
    while(1){
        int opcao;
        std::cout << "Menu:\n1. Ligar lampada\n2. Desligar lampada\n3. Mostrar estado da lampada\n4. Trocar cor da lampada\n5. Sair\nEscolha uma opcao: ";
        std::cin >> opcao;
        if(opcao == 1){
            lampada.ligar();
        } else if(opcao == 2){
            lampada.desligar();
        } else if(opcao == 3){
            lampada.mostrarEstado();
        } else if(opcao == 4){
            std::string novaCor;
            std::cout << "Digite a nova cor da lampada: ";
            std::cin >> novaCor;
            lampada.trocarCor(novaCor);
        } else if(opcao == 5){
            return 0;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}