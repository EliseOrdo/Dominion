#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "Carte.h"

class Joueur {
    int id, nb_action, nb_achat, nb_piece;
    std::vector<Carte> main, deck, defausse, en_jeu;
public :
    Joueur();
    void achat();
    void jouer();
    void piocher(int nb);
    Carte reveler();
    int getIndCarteMain(std::string nom);
    void ecarter(std::string nom);
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