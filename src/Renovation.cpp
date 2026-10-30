#include "Renovation.h"
#include "Jeu.h"
#include <iostream>

Renovation::Renovation(){
    nom = "Rénovation";
    cout = 4;
    description = "Écartez une carte de votre main. Recevez une carte coûtant jusqu'à 2 pieces de plus que la carte écartée.;";
}

void Renovation::effet(Joueur* j){
    std::cout<<"Choisissez une carte à écarter.\n";
    Carte* c = Jeu::choisirCarte(j->getMain());
    std::cout<<"Voici les cartes que vous pouvez recevoir.\n";
    Carte* rec = Jeu::choisirCarte(Jeu::getListeCartesPiochesCoutMax(c->getCout()+2));
    j->Carte2Defausse(Jeu::prendreCartePioches(rec));
}