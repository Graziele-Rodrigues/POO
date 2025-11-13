#include <iostream>
#include <string>

class Mensagem {
public:
    virtual ~Mensagem() {};
    virtual void enviar(){
        std::cout << "Enviando mensagem padrao." << std::endl;
    }
};

class MensagemTexto : public Mensagem {
public:
    void enviar() override {
        std::cout << "Enviando mensagem de texto: mensagem.txt" << std::endl;
    }
}; 

class MensagemVoz : public Mensagem {
public:
    void enviar() override {
        std::cout << "Enviando mensagem de voz: audio de 60 s" << std::endl;
    }
};

class MensagemImagem : public Mensagem {
public:
    void enviar() override {
        std::cout << "Enviando mensagem de imagem: pordosol.png" << std::endl;
    }
};

int main(){
    MensagemTexto msgTexto;
    MensagemVoz msgVoz;
    MensagemImagem msgImagem;
    MensagemTexto msgTexto2;
    MensagemVoz msgVoz2;

    Mensagem *mensagemPtr[5] = {&msgTexto, &msgVoz, &msgImagem, &msgTexto2, &msgVoz2};
    for(Mensagem* msg : mensagemPtr){
        msg->enviar();
    }

    return 0;
}



