#include <iostream>
#include "playlist.h"

int main() {
    Playlist minhaPlaylist;
    minhaPlaylist.nome = "MPBs Classicas";

    // Adicionando 5 músicas
    minhaPlaylist.adicionarMusica("Tom Jobim - Garota de Ipanema");
    minhaPlaylist.adicionarMusica("Chico Buarque - A Banda");
    minhaPlaylist.adicionarMusica("Caetano Veloso - Sampa");
    minhaPlaylist.adicionarMusica("Gilberto Gil - Aquele Abraço");
    minhaPlaylist.adicionarMusica("Elis Regina - Como Nossos Pais");


    // Tocando todas em sequência
    for (int i = 0; i < 6; i++) { 
        minhaPlaylist.tocarProxima();
        minhaPlaylist.mostrarMusicaAtual();
        std::cout << "--------------------------------------------" << std::endl;
    }

    return 0;
}