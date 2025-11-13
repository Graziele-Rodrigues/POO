#include <iostream>
#include <string>

class Figura {
public:
    float largura;
    float altura;
    std::string cor;
    
    Figura(float l, float a, const std::string& c = "sem cor"){
        largura = l;
        altura = a;
        cor = c;
    }

    virtual float CalcularArea() {
        return 0.0f;
    }
};

class Retangulo : public Figura {
public:
    
    Retangulo(float l, float a, const std::string c = "sem cor") : Figura(l, a, c) {}

    float CalcularArea() override {
        return largura * altura;
    }
};

class Triangulo : public Figura {
public:
    Triangulo(float l, float a, const std::string c = "sem cor") : Figura(l, a, c) {}
    
    float CalcularArea() override {
        return (largura * altura) / 2.0f;
    }
};

int main() {
    
    Retangulo ret1(5.0, 3.0, "vermelho");
    Retangulo ret2(4.0, 2.0);
    Triangulo tri1(6.0, 4.0, "azul");
    std::cout << "Area do retangulo 1: " << ret1.CalcularArea() << std::endl;
    std::cout << "Area do retangulo 2: " << ret2.CalcularArea() << std::endl;
    std::cout << "Area do triangulo 1: " << tri1.CalcularArea() << std::endl;
    
    return 0;
}