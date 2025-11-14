
// O SRP diz que cada classe deve ter apenas uma responsabilidade e, portanto, apenas um motivo para mudar. 
// Comum usar composicao para separar responsabilidades.

#include <iostream>
#include <string>
#include <vector>

class Usuario {
public:
    std::string nome;
    std::string email;
    std::string senha;

    Usuario(std::string n, std::string e, std::string s){
        nome = n;
        email = e;
        senha = s;
    }

    void alterarSenha(std::string novaSenha) {
        senha = novaSenha;
    }

    void atualizarEmail(std::string novoEmail) {
        email = novoEmail;
    }

};

class CadastroUsuario {
private:
    std::vector<Usuario*> usuarios;

public:
    void adicionarUsuario(Usuario* usuario) { 
        usuarios.push_back(usuario);
    }

    std::vector<Usuario*> getUsuarios() const {
        return usuarios;
    }
};

class ServicoEmail {
public:
    void enviarEmailBoasVindas(Usuario usuario) {
        std::cout << "Bem-vindo " << usuario.nome << " - " << usuario.email << std::endl;
    }
};

class ServicoRelatorio {
public:
    void gerarRelatorioUsuarios(std::vector<Usuario*> usuarios) { // Recebe a lista de usuários como parâmetro
        for (auto usuario : usuarios) { 
            std::cout << "Nome: " << usuario->nome << ", Email: " << usuario->email << std::endl;
        }
    }
};

int main() {
    std::cout << "=== Sistema de Cadastro de Usuarios ===\n\n";

    Usuario* user1 = new Usuario("Joao Silva", "joao@email.com", "senha123");
    Usuario* user2 = new Usuario("Maria Santos", "maria@email.com", "senha456");
    Usuario* user3 = new Usuario("Pedro Oliveira", "pedro@email.com", "senha789");

    CadastroUsuario cadastro;
    cadastro.adicionarUsuario(user1); 
    cadastro.adicionarUsuario(user2);
    cadastro.adicionarUsuario(user3);

    ServicoEmail emailService;
    std::cout << "--- Enviando emails de boas-vindas ---\n";
    emailService.enviarEmailBoasVindas(*user1);
    emailService.enviarEmailBoasVindas(*user2);
    emailService.enviarEmailBoasVindas(*user3);

    std::cout << "\n--- Alterando dados do usuario ---\n";
    user1->alterarSenha("novaSenha123");
    user1->atualizarEmail("joao.novo@email.com");
    std::cout << "Dados atualizados: " << user1->nome << " - " << user1->email << std::endl;

    std::cout << "\n--- Gerando relatorio ---\n";
    ServicoRelatorio relatorio;
    relatorio.gerarRelatorioUsuarios(cadastro.getUsuarios()); 

    delete user1;
    delete user2;
    delete user3;

    return 0;
}