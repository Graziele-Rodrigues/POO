#include <iostream>
#include <string>

#include "robo.h"

int main(){
    Robo robo1;
    std::cout << "Digite o nome do robo: ";
    std::cin >> robo1.nome;
    std::cout << "Digite a energia inicial do robo (0 - 100): ";
    int energiaInput;
    std::cin >> energiaInput;
    if(energiaInput < 0) energiaInput = 0;
    if(energiaInput > 100) energiaInput = 100;
    robo1.energia = energiaInput;

    while(1){
        int opcao;
        std::cout << "\nMenu:\n1. Mostrar Status\n2. Executar Tarefa\n3. Recarregar\n4. Sair\nEscolha uma opcao: ";
        std::cin >> opcao;
        if(opcao == 1){
            robo1.mostrarStatus();
        } else if(opcao == 2){
            robo1.executarTarefa();
        } else if(opcao == 3){
            robo1.recarregar();
        } else if(opcao == 4){
            return 0;
        } else {
            std::cout << "Opcao invalida! Tente novamente." << std::endl;
        }
    }

    return 0;
}