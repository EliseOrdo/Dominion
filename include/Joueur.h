#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "Carte.h"

class Joueur {
    int id, nb_action, nb_achat, nb_piece;
    std::vector<Carte> main, deck, defausse, en_jeu;
public :
    void achat();
    void jouer();
    void piocher();
    Carte reveler();
    void melanger();
};

#endif