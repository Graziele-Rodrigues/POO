#include "playlist.h"
#include <iostream>
#include <vector>
#include <string>



void Playlist::adicionarMusica(std::string musica) {
    musicas.push_back(musica);
}

void Playlist::tocarProxima() {
    if (musicas.empty()) {
        std::cout << "Playlist vazia." << std::endl;
        return;
    }
    indiceAtual++;
    if (indiceAtual >= (int)musicas.size()) { // musica.size retorna size_t que eh unsigned e indiceAtual eh int que eh signed
        std::cout << "Fim da playlist..." << std::endl;
        return;
    }
    std::cout << "Tocando: " << musicas[indiceAtual] << std::endl;
}

void Playlist::mostrarMusicaAtual() {
    if (indiceAtual >= 0 && indiceAtual < (int)musicas.size()) { // musica.size retorna size_t que eh unsigned e indiceAtual eh int que eh signed
        std::cout << "Musica atual: " << musicas[indiceAtual] << std::endl;
    } else {
        std::cout << "Nenhuma musica esta tocando no momento." << std::endl;
    }
}
