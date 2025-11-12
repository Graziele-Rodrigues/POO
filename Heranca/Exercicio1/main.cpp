#include <iostream>
#include <string>

class Funcionario {
public:
    std::string nome;
    float salario;

    // Construtor
    Funcionario(std::string n, float s){
        nome = n;
        salario = s;
    }
};

class Gerente : public Funcionario {
public:
    std::string setor;

    // Construtor onde chamamos o construtor da classe base e inicializamos o atributo adicional
    Gerente(std::string n, float s, std::string set) : Funcionario(n, s){
        setor = set;
    }
};

int main() {
    Gerente gerente("Ana Silva", 7500.00f, "Vendas");

    std::cout << "Nome: " << gerente.nome << std::endl;
    std::cout << "Salario: " << gerente.salario << std::endl;
    std::cout << "Setor: " << gerente.setor << std::endl;

    return 0;
}