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
    static std::vector<Carte*> getCartesVictoire(std::vector<Carte*> listeCartes);
    static std::vector<Carte*> getCartesRoyaume(std::vector<Carte*> listeCartes);


    Joueur();
    void tour();
    void achat();
    void jouerCarte();

    void piocher(int nb);
    Carte* reveler();
    void ecarter(std::string nom);
    void ecarter_en_jeu(std::string nom);
    void enleverDeMain(std::string nom);
    void defausser(Carte* carte);
    void melanger();
    void poserCarte(Carte* carte);

    int getIndCarteMain(std::string nom);
    
    void travailTermine();
    int getId();

    Carte* montrerCarteVictoire();

    int getNbAction();
    int getNbAchat();
    int getNbPiece();
    std::vector<Carte*> getMain();
    std::vector<Carte*> getDefausse();
    std::vector<Carte*> getDeck();

    void addNbAction(int nb);
    void addNbAchat(int nb);
    void addNbPiece(int nb);

    void Carte2Main(Carte* carte);
    void Carte2Defausse(Carte* carte);
    void Carte2Deck(Carte* carte);
    int getScore();
    
};

#endif