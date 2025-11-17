// Módulos de alto nível não devem depender de módulos de baixo nível, ambos devem depender de abstrações.
// por exemplo, uma classe de alto nivel ProcessadorDePagamento não deve depender diretamente de uma classe de baixo nível PagamentoComCartaoDeCredito.
// em vez disso, ambos devem depender de uma abstração, como uma interface IPagamento

#include <iostream>
#include <vector>

class INotificacao {
public:
    virtual void enviarNotificacao(const std::string& mensagem) = 0;
    virtual ~INotificacao() = default;
};

class EmailNotificacao : public INotificacao {
public: 
    void enviarNotificacao(const std::string& mensagem) override {
        std::cout << "Enviando notificacao por email: " << mensagem << std::endl;
    }
};


class SMSNotificacao : public INotificacao {
public:
    void enviarNotificacao(const std::string& mensagem) override {
        std::cout << "Enviando notificacao por SMS: " << mensagem << std::endl;
    }
};


class ProcessadorDePagamento {
public:    
    
    INotificacao *notificacao; // ponteiro que aponta para objeto que implemente INotificacao

    ProcessadorDePagamento(INotificacao& n) { // construtor recebe uma referencia para o objeto que implementa INotificacao
        notificacao = &n; // guarda o endereço desse objeto no ponteiro notificacao
    }


    void processarPagamento() {
        std::cout << "Processando pagamento..." << std::endl;
        notificacao->enviarNotificacao("Pagamento realizado com sucesso!");
    }
};


int main() {
    EmailNotificacao emailNotificacao;
    SMSNotificacao smsNotificacao;

    std::vector<INotificacao*> notificacoes = { &emailNotificacao, &smsNotificacao };
    for (auto* n : notificacoes) { // iterar sobre cada objeto que implementa INotificacao
        ProcessadorDePagamento processador(*n); // criar ProcessadorDePagamento com a notificacao atual usando referencia 
        processador.processarPagamento();
    }

    return 0;
}