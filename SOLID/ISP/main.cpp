//Nenhum cliente deve ser forçado a depender de métodos que não utiliza.
// Em vez de criar uma interface “gigante” com muitos métodos, divida-a em interfaces menores e mais específicas.

#include <iostream>
#include <vector>

// VIOLANDO O ISP
/*
class IMidiaPlayer {
public:
    virtual void reproduzirMusica() = 0;
    virtual void reproduzirVideo() = 0;
    virtual void gravarAudio() = 0;
};

class PlayerMusicaSimples : public IMidiaPlayer {
public:
    void reproduzirMusica() override {
        std::cout << "Reproduzindo música..." << std::endl;
    }
    void reproduzirVideo() override {
        // Não faz sentido para este player
        std::cout << "Não suporta vídeo." << std::endl;
    }
    void gravarAudio() override {
        // Não faz sentido para este player
        std::cout << "Não suporta gravação." << std::endl;
    }
};

class GravadorDeAudio : public IMidiaPlayer {
public:
    void reproduzirMusica() override {
        std::cout << "Não suporta música." << std::endl;
    }
    void reproduzirVideo() override {
        std::cout << "Não suporta vídeo." << std::endl;
    }
    void gravarAudio() override {
        std::cout << "Gravando áudio..." << std::endl;
    }
};
*/

// SEGUINDO O ISP
class IReprodutorMusica {
public:
    virtual void reproduzirMusica() = 0;
};

class IReprodutorVideo {
public:
    virtual void reproduzirVideo() = 0;
};

class IGravadorAudio {
public:
    virtual void gravarAudio() = 0;
};

class PlayerMusicaSimples : public IReprodutorMusica {
public:
    void reproduzirMusica() override {
        std::cout << "Reproduzindo musica..." << std::endl;
    }
};

class GravadorDeAudio : public IGravadorAudio {
public:
    void gravarAudio() override {
        std::cout << "Gravando audio..." << std::endl;
    }
};

class PlayerVideo : public IReprodutorVideo {
public:
    void reproduzirVideo() override {
        std::cout << "Reproduzindo video..." << std::endl;
    }
};

class MediaMultifuncional : public IReprodutorMusica, public IReprodutorVideo, public IGravadorAudio {
public:
    void reproduzirMusica() override {
        std::cout << "MediaMultifuncional: Reproduzindo musica..." << std::endl;
    }
    void reproduzirVideo() override {
        std::cout << "MediaMultifuncional: Reproduzindo video..." << std::endl;
    }
    void gravarAudio() override {
        std::cout << "MediaMultifuncional: Gravando audio..." << std::endl;
    }
};


int main() {
    GravadorDeAudio gravador;
    gravador.gravarAudio();

    PlayerVideo playerVideo;
    playerVideo.reproduzirVideo();

    PlayerMusicaSimples playerMusica;

    MediaMultifuncional mediaCenter;
    mediaCenter.reproduzirVideo();
    mediaCenter.gravarAudio();

    std::vector<IReprodutorMusica*> musicas = { &playerMusica, &mediaCenter };

    for (IReprodutorMusica* music : musicas) {
        music->reproduzirMusica();
    }

    return 0;
}
