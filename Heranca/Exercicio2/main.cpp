#include <iostream>
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
        std::cout << "Nome: " << nome << ", Preco: " << preco << "\n";
    }
};

class Livro : public Produto {
public:
    int ISBN;

    Livro(std::string n, float p, int isbn) : Produto(n, p) {
        ISBN = isbn;
    }

    void exibirDetalhes() override {
        std::cout << "Nome: " << nome << ", Preco: " << preco << ", ISBN: " << ISBN << "\n";
    }
}; 

int main(){
    Produto p1("Caneta", 2.5);
    Produto p2("Caderno", 15.0);
    Produto p3("Mochila", 120.0);
    Produto p4("Estojo", 10.0);

    Livro l1("O Senhor dos Aneis", 50.0, 123456789);
    Livro l2("1984", 30.0, 987654321);
    Livro l3("Algoritmos", 25.0, 112233445);
    Livro l4("Estruturas de Dados", 40.0, 556677889);

    std::cout << "Detalhes dos Produtos:" << std::endl;
    std::cout << "----------------------" << std::endl;
    p1.exibirDetalhes();
    p2.exibirDetalhes();
    p3.exibirDetalhes();
    p4.exibirDetalhes();

    std::cout << "\nDetalhes dos Livros:" << std::endl;
    std::cout << "----------------------" << std::endl;
    l1.exibirDetalhes();
    l2.exibirDetalhes();
    l3.exibirDetalhes();
    l4.exibirDetalhes();
    

    return 0;



}