#include "Milice.h"
#include "Jeu.h"
#include <iostream>

Milice::Milice(){
    nom = "Milice";
    cout = 4;
    description = "+3 pieces, Tous vos adversaires défaussent leurs cartes de façon à n'avoir que 3 cartes en main.;";
}

void Milice::effet(Joueur* j){
    j->addNbPiece(3);
    for(Joueur* adv:Jeu::getJoueursAffectes(j)){
        std::cout<<"Joueur "<<adv->getId()<<" :\n";
        while(adv->getMain().size()>3){
            std::cout<<"choisissez une carte à defausser :\n";
            Carte* c = Jeu::choisirCarte(adv->getMain());
            adv->enleverDeMain(c->getNom());
            adv->defausser(c);
        }
    }
    std::cout<<"Fin de l'effet, retour tour joueur "<<j->getId()<<std::endl;
}