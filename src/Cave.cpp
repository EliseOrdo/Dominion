#include "Cave.h"
#include <iostream>
#include "Jeu.h"

Cave::Cave(){
    nom = "Cave";
    cout = 2;
    description = "+1 Action, Défaussez autant de cartes que vous voulez. +1 Carte par carte défaussée.;";
}

void Cave::effet(Joueur* j){
    j->addNbAction(1);
    std::vector<Carte*> lc;
    std::cout<<"Combien de cartes souhaitez-vous défausser ?\n";
    int nb;
    std::cin>>nb;
    for(int i=0; i<nb;i++){
        Carte* c =Jeu::choisirCarte(j->getMain());
        lc.push_back(c);
        j->enleverDeMain(c->getNom()); 
    }
    for(Carte* c: lc){
        j->defausser(c);
    }
    j->piocher(nb);
}