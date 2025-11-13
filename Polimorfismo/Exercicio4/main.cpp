#include <iostream>

class Pagamento {
public:
    virtual ~Pagamento() {}
    virtual void processarPagamento() {
        std::cout << "Processando pagamento generico." << std::endl;
    }
};

class PagamentoPix : public Pagamento {
public:
    void processarPagamento() override {
        std::cout << "Processando pagamento via Pix!" << std::endl;
        std::cout << "Transferencia instantanea em andamento." << std::endl;
    }
};

class PagamentoCartaoCredito : public Pagamento {
public:
    void processarPagamento() override {
        std::cout << "Processando pagamento com cartao de credito!" << std::endl;
        std::cout << "Por favor, aguarde a autorizacao da operadora." << std::endl;
    }
};

class PagamentoBoleto : public Pagamento {
public:
    void processarPagamento() override {
        std::cout << "Processando pagamento via boleto bancario! " << std::endl;
        std::cout << "Processamento pode levar ate 3 dias uteis." << std::endl;
    }
};


void realizarPagamento(Pagamento* metodo) {
    metodo->processarPagamento();
    std::cout << "-------------------------------------------------------" << std::endl;
}

int main(){
    PagamentoPix pix;
    PagamentoCartaoCredito cartao;
    PagamentoBoleto boleto;

    Pagamento* metodos[] = { &pix, &cartao, &boleto };

    std::cout << "Iniciando processamento de pagamentos:\n";
    std::cout << "-------------------------------------------------------" << std::endl;
    for (Pagamento* metodo : metodos) {
        realizarPagamento(metodo);
    }

    return 0;
}