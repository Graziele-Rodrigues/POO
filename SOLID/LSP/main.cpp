// Objetos de uma classe derivada devem poder substituir objetos da classe base sem alterar a correção do programa.
// se você tem uma classe Base e uma classe Derivada que herda de Base, 
// qualquer código que funcione com Base deve funcionar corretamente com Derivada sem precisar saber que é uma derivada

// Se Base tem um método calcular(), a classe Derivada não deve mudar o comportamento esperado

#include <iostream>


class Cartao {
public: 
    virtual ~Cartao() = default;
    virtual void autorizarPagamento() {
        std::cout << "Autorizando pagamento com cartao generico." << std::endl;
    };

    virtual void ConsultarLimite() {
        std::cout << "Consultando limite do cartao generico." << std::endl;
    };
};

class CartaoCredito : public Cartao {
public:
    void autorizarPagamento() override {
        std::cout << "Autorizando pagamento com cartao de credito." << std::endl;
    };

    void ConsultarLimite() override {
        std::cout << "Consultando limite do cartao de credito." << std::endl;
    };
};

class CartaoDebito : public Cartao {
public:
    void autorizarPagamento() override {
        std::cout << "Autorizando pagamento com cartao de debito." << std::endl;
    };

    void ConsultarLimite() override {
        std::cout << "Consultando limite do cartao de debito." << std::endl;
    };
};


void processarPagamento(Cartao& cartao) {
    cartao.autorizarPagamento();
    cartao.ConsultarLimite();
}

int main() {
    CartaoCredito cartaoCredito;
    CartaoDebito cartaoDebito;

    processarPagamento(cartaoCredito); 
    processarPagamento(cartaoDebito);  

    return 0;
}


