// Entidades de software (classes, módulos, funções) devem estar abertas para extensão, mas fechadas para modificação
// Ser possível conseguir adicionar novas funcionalidades sem alterar o código existente.
// Não precisar mudar o código já escrito para implementar algo novo.
// Usar herança e polimorfismo para conseguir isso.

#include <iostream>

class Frete {
public:
    virtual ~Frete() = default;
    virtual float calcularFrete(float peso) = 0; 
};

class FreteNormal : public Frete {
public:
    virtual ~FreteNormal() = default;

    float calcularFrete(float peso)  override {
        return peso * 5.0;
    }
};

class FreteExpresso : public Frete {
public:
    virtual ~FreteExpresso() = default;

    float calcularFrete(float peso) override {
        return peso * 10.0;
    }
};


class Pedido {
public:
    float peso;
    Frete* estrategiaFrete; // Ponteiro que referencia a estrategia de frete

    Pedido(float p, Frete* f) { // Ao criar o pedido, passa o peso e a estrategia de frete
        peso = p;
        estrategiaFrete = f;
    }

    float calcularCustoFrete() { 
        return estrategiaFrete->calcularFrete(peso); // retorna o custo do frete usando a estrategia definida
    }
};


// ciclo: cria o objeto com frete desejado  -> instancia o pedido passando o frete -> calcula o custo do frete usando a estrategia escolhida
int main() {
    Frete* freteNormal = new FreteNormal(); // aqui cria objeto do tipo frete normal
    Pedido pedido1(10.0, freteNormal); 
    std::cout << "Custo do frete normal: " << pedido1.calcularCustoFrete() << std::endl;

    Frete* freteExpresso = new FreteExpresso();
    Pedido pedido2(10.0, freteExpresso); 
    std::cout << "Custo do frete expresso: " << pedido2.calcularCustoFrete() << std::endl;

    delete freteNormal;
    delete freteExpresso;

    return 0;
}