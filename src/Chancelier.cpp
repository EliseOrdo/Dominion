#include "Chancelier.h"
#include <iostream>
#include "Jeu.h"

Chancelier::Chancelier(){
    nom = "Chancelier";
    cout = 3;
    description = "+2 pieces, Vous pouvez immédiatement défausser votre deck.;";//ne compte pas comm défausser chaque carte, cad n'active pas les effets sur les cartes qui demandent à etre defaussees
}

void effet(Joueur j){
    std::cout<<"Voulez-vous défausser tout votre deck ?\n"; 
    if(Jeu::OuiNon()){
        for(Carte* c:j.getDeck()){
            j.getDefausse().push_back(c);
        }
        j.getDeck().clear();
    }
}