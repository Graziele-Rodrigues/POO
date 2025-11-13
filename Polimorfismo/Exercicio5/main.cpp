#include <iostream>
#include <string>

class Personagem {
public:
    int forca;
    int vida;

    Personagem(int f, int v){
        forca = f;
        vida = v;
    }

    virtual ~Personagem() {};
    virtual void atacar(){
        std::cout << "Ataque padrao do personagem." << std::endl;
    }

    virtual void receberDano(int dano){
        vida -= dano;
        std::cout << "Recebeu " << dano << " de dano (vida=" << vida << ")\n";
        if(vida <= 0) std::cout << "Personagem caiu em batalha!\n";
    }

    virtual void especial(){
        std::cout << "Usando habilidade especial padrao." << std::endl;
    }

    bool estaVivo() const { return vida > 0; }
};

class Mago : public Personagem {
public:
    Mago() : Personagem(5, 50) {}

    void atacar() override {
        std::cout << "Enviando bola de fogo!" << std::endl;
    }

    void especial() override {
        std::cout << "Recuperando vida com magia!" << std::endl;
        vida += 5;
    }
    
};

class Guerreiro : public Personagem {
public:
    Guerreiro() : Personagem(10, 100) {}

    void atacar() override {
        std::cout << "Golpeando com espada pesada" << std::endl;
    }
    // guerreiro tem armadura simples: reduz dano em 2
    void receberDano(int dano) override {
        int d = dano - 2;
        if(d < 0) d = 0;
        Personagem::receberDano(d); // chama o metodo base
    }

    void especial() override {
        std::cout << "Entrando em modo berserker!" << std::endl;
        forca += 5;
    }
};

class Arqueiro : public Personagem {
public:
    Arqueiro() : Personagem(7, 70) {}

    void atacar() override {
        std::cout << "Disparando flecha precisa!" << std::endl;
    }

    void especial() override {
        std::cout << "Atirando flechas em chuva!" << std::endl;
    }
};


int main() {
    int rodada=0;
    Mago mago1;
    Guerreiro guerreiro1;
    Arqueiro arqueiro1;
    Mago mago2;

    Personagem* grupo1[] = { &mago1, &guerreiro1 };
    Personagem* grupo2[] = { &arqueiro1, &mago2 };

    std::cout << "Luta entre grupos:" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    while (true) {
        rodada++;
        std::cout << "\nRodada " << rodada << ":\n";

        // Grupo 1 ataca
        for (Personagem* p1 : grupo1) {
            if (!p1->estaVivo()) continue; // se aquele personagem morreu, pula
 
            // A cada 3 rodadas, usa especial
            if (rodada % 3 == 0) {
                p1->especial();
            }

            for (Personagem* p2 : grupo2) { 
                if (p2->estaVivo()) { // ataca o primeiro vivo do grupo inimigo
                    p1->atacar();
                    p2->receberDano(p1->forca);
                    break;
                }
            }
        }

        // Verifica se grupo 2 morreu
        bool grupo2Vivo = false;
        for (Personagem* p : grupo2) if (p->estaVivo()) grupo2Vivo = true;
        if (!grupo2Vivo) {
            std::cout << "\nGrupo 1 venceu a batalha!" << std::endl;
            break; // sai do loop se o grupo 2 morreu
        }

        // Grupo 2 ataca
        for (Personagem* p2 : grupo2) {
            if (!p2->estaVivo()) continue;

            // A cada 3 rodadas, usa especial
            if (rodada % 3 == 0) {
                p2->especial();
            }

            for (auto* p1 : grupo1) {
                if (p1->estaVivo()) {
                    p2->atacar();
                    p1->receberDano(p2->forca);
                    break;
                }
            }
        }

        // Verifica se grupo 1 morreu
        bool grupo1Vivo = false;
        for (auto* p : grupo1) if (p->estaVivo()) grupo1Vivo = true;
        if (!grupo1Vivo){
            std::cout << "\nGrupo 2 venceu a batalha!" << std::endl;
            break; // sai do loop se o grupo 1 morreu
        }
    }

    std::cout << "Fim da luta!\n";
    return 0;
}