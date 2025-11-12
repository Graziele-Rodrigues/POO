#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <string>

class Playlist {
public:
    std::string nome;
    std::vector<std::string> musicas;
    int indiceAtual = -1; 

    void adicionarMusica(std::string musica);
    void tocarProxima();
    void mostrarMusicaAtual();
    
};

#endif // PLAYLIST_H