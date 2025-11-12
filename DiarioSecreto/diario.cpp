#include <iostream>
#include <string>

#include "diario.h"


void Diario::escrever(std::string texto_digitado, std::string senha_digitada){
    if(senha_digitada == senha){
        texto = texto_digitado;
        std::cout << "Texto salvo com sucesso!" << std::endl;
    } else {
        std::cout << "Senha incorreta! Texto nao salvo." << std::endl;
    }
}

void Diario::ler(std::string senha_digitada){
    if(senha_digitada == senha){
        std::cout << "Conteudo do diario: " << texto << std::endl;
    } else {
        std::cout << "Acesso negado!" << std::endl;
    }
}
