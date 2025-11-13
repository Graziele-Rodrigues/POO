#include <iostream>

class CriaturaMagica {
public:
    virtual ~CriaturaMagica() {};
    virtual void emitirSom(){
        std::cout << "Emitindo som padrao." << std::endl;
    }
};

class Grifo : public CriaturaMagica {
public:
    void emitirSom() override {
        std::cout << "Grifo grita!" << std::endl;
    }
};

class Dragao : public CriaturaMagica {
public:
    void emitirSom() override {
        std::cout << "Dragao ruge!" << std::endl;
    }
};

class Fenix : public CriaturaMagica {
public:
    void emitirSom() override {
        std::cout << "Fenix canta!" << std::endl;
    }
};


void fazerBarulho(CriaturaMagica* criatura) {
    criatura->emitirSom();
}


int main() {
    Grifo grifo;
    Dragao dragao;
    Fenix fenix;

    CriaturaMagica* criaturas[] = { &grifo, &dragao, &fenix };

    std::cout << "Emitindo sons das criaturas magicas:\n";
    for (CriaturaMagica* c : criaturas) {
        fazerBarulho(c);
    }

    return 0;
}
