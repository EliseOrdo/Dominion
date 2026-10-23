#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "Carte.h"

class Joueur {
    int id, nb_action, nb_achat, nb_piece;
    std::vector<Carte> main, deck, defausse, en_jeu;
public :
    Joueur(int nb_act, int nb_ach, int nb_pie) : nb_action(nb_act), nb_achat(nb_ach), nb_piece(nb_pie) {};
    void achat();
    void jouer();
    void piocher(int nb);
    Carte reveler();
    void melanger();
    void finDeTour();
    int getNbAction();
    int getNbAchat();
    int getNbPiece();
    void addNbAction(int nb);
    void addNbAchat(int nb);
    void addNbPiece(int nb);
};

#endif