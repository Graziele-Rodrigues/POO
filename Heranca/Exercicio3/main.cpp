#include <iostream>
#include <string>

class Pessoa {
public: 
    std::string nome;

    Pessoa(std::string n){
        nome = n;
    }

    virtual void apresentar() {
        std::cout << "Nome: " << nome << std::endl;
    }
};

class Estudante : public Pessoa {
public:
    int matricula;

    Estudante(std::string n, int m) : Pessoa(n){
        matricula = m;
    }

    void apresentar() override {
        Pessoa::apresentar();
        std::cout << "Matricula: " << matricula << std::endl;
    }
};

int main(){
    Pessoa p("Alice");
    Estudante e("Joao", 12345);

    std::cout << "Apresentacao Pessoa:" << std::endl;
    std::cout << "-------------------" << std::endl;
    p.apresentar();
    std::cout << "\nApresentacao Estudante:" << std::endl;
    std::cout << "----------------------" << std::endl;
    e.apresentar();

    return 0;
}