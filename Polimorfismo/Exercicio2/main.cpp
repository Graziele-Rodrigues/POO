#include <iostream>
#include <string>

class Mutante {
public:
    virtual void usarPoder(){
        std::cout << "Usando poder padrao." << std::endl;
    }
};

class Wolverine : public Mutante {
public:
    void usarPoder() override {
        std::cout << "Wolverine usa garras de adamantium!" << std::endl;
    }
};

class JeanGrey : public Mutante {
public:
    void usarPoder() override {
        std::cout << "Telepatia e telecinese ativadas!" << std::endl;
    }
};

class Noturno : public Mutante {
public:
    void usarPoder() override {
        std::cout << "BAMF! Teletransportando..." << std::endl;
    }
};

int main() {
    Wolverine wolv;
    JeanGrey jean;
    Noturno night;

    Mutante* equipe[] = { &wolv, &jean, &night };

    std::cout << "Iniciando batalha dos mutantes:\n";
    for (Mutante* m : equipe) {
        m->usarPoder();
    }

    return 0;
}

