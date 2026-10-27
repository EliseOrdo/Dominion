#include <random>
#include <iostream>
#include "Joueur.h"
#include "Cuivre.h"
#include "Jeu.h"
#include "Bucheron.h"

int main(){
    Joueur j = Joueur();
    Carte* b = new Bucheron();
    Carte* c = new Cuivre();
    std::vector<Carte*> liste = { b, c};
    Jeu::choisirCarte(liste);
    delete b;
    delete c;
    return 0;
}