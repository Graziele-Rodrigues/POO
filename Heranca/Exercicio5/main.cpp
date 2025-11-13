#include <iostream>
#include <vector>
#include <string>

class Produto {
public:
    std::string nome;
    float preco;

    Produto(std::string n, float p) {
        nome = n;
        preco = p;
    }

    virtual void exibirDetalhes() {
        std::cout << "Produto: " << nome << ", Preco: " << preco << std::endl;
    }
};

class Computador : public Produto {
public:
    std::string especificacoes;

    Computador(std::string n, float p, std::string e) : Produto(n, p) {
        especificacoes = e;
    }

    void exibirDetalhes() override {
        std::cout << "Computador: " << nome << ", Preco: " << preco
                  << ", Especificacoes: " << especificacoes << std::endl;
    }

    void aplicarDesconto() {
        preco -= preco * 0.10; // 10%
    }
};

class Smartphone : public Produto {
public:
    int capacidadeBateria;

    Smartphone(std::string n, float p, int c) : Produto(n, p) {
        capacidadeBateria = c;
    }

    void exibirDetalhes() override {
        std::cout << "Smartphone: " << nome << ", Preco: " << preco
                  << ", Capacidade da Bateria: " << capacidadeBateria << "mAh" << std::endl;
    }

    void aplicarDesconto() {
        preco -= preco * 0.05; // 5%
    }
};

int main() {
    std::vector<Computador> computadores;
    std::vector<Smartphone> smartphones;

    int opcao;
    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Adicionar Computador\n";
        std::cout << "2. Adicionar Smartphone\n";
        std::cout << "3. Listar Computadores\n";
        std::cout << "4. Listar Smartphones\n";
        std::cout << "5. Aplicar desconto em Computador\n";
        std::cout << "6. Aplicar desconto em Smartphone\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        // Limpa o buffer depois de ler a opção
        std::cin.ignore(1000, '\n');

        switch (opcao) {
            case 1: {
                std::string nome, especificacoes;
                float preco;

                std::cout << "Nome do computador: ";
                std::getline(std::cin, nome);

                std::cout << "Preco: ";
                std::cin >> preco;

                // Limpa o buffer depois de ler preco
                std::cin.ignore(1000, '\n');

                std::cout << "Especificacoes: ";
                std::getline(std::cin, especificacoes);

                computadores.push_back(Computador(nome, preco, especificacoes));
                break;
            }
            case 2: {
                std::string nome;
                float preco;
                int bateria;

                std::cout << "Nome do smartphone: ";
                std::getline(std::cin, nome);

                std::cout << "Preco: ";
                std::cin >> preco;

                std::cout << "Capacidade da bateria (mAh): ";
                std::cin >> bateria;

                // Limpa o buffer depois de ler bateria
                std::cin.ignore(1000, '\n');

                smartphones.push_back(Smartphone(nome, preco, bateria));
                break;
            }
            case 3:
                std::cout << "\n--- Computadores ---\n";
                for (size_t i = 0; i < computadores.size(); i++) {
                    std::cout << i << ". ";
                    computadores[i].exibirDetalhes();
                }
                break;
            case 4:
                std::cout << "\n--- Smartphones ---\n";
                for (size_t i = 0; i < smartphones.size(); i++) {
                    std::cout << i << ". ";
                    smartphones[i].exibirDetalhes();
                }
                break;
            case 5: {
                int index;
                std::cout << "Digite o índice do computador para aplicar desconto: ";
                std::cin >> index;
                computadores[index].aplicarDesconto();
                std::cout << "Desconto aplicado!\n";
                break;
            }
            case 6: {
                int index;
                std::cout << "Digite o índice do smartphone para aplicar desconto: ";
                std::cin >> index;
                smartphones[index].aplicarDesconto();
                std::cout << "Desconto aplicado!\n";
                break;
            }
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
