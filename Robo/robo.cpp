#include <iostream>
#include <string>
#include "robo.h"

void Robo::executarTarefa(){
    if(energia <= 10){
        std::cout << "Robo " << nome << " sem energia suficiente para executar a tarefa!" << std::endl;
        return;
    } else{
        std::cout << "Robo " << nome << " executando tarefa" << std::endl;
        energia -= 10;
    }
}

void Robo::recarregar(){
    std::cout << "Robo " << nome << " recarregando energia" << std::endl;
    energia  = 100;
}

void Robo::mostrarStatus(){
    std::cout << "Robo: " << nome << ", Energia: " << energia << std::endl;
}

