#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "Carte.h"

class Joueur {
    int id, nb_action, nb_achat, nb_piece;
    std::vector<Carte*> main, deck, defausse, en_jeu;
public :
    static int dernier_id;

    static std::vector<Carte*> getCartesTresor(std::vector<Carte*> listeCartes);

    Joueur();
    void achat();
    void jouer(); //Pas encore fait

    void piocher(int nb);
    Carte* reveler();
    void ecarter(std::string nom);

    int getIndCarteMain(std::string nom);
    
    void melanger();
    void finDeTour();
    int getId();

    int getNbAction();
    int getNbAchat();
    int getNbPiece();
    std::vector<Carte*> getMain();

    void addNbAction(int nb);
    void addNbAchat(int nb);
    void addNbPiece(int nb);
    
    void recevoirCarte(Carte* carte);
    void prendreCarte(Carte* carte);
    int getScore();
    
};

#endif