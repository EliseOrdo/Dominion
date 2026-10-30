#include "PreteurSurGages.h"
#include "Cuivre.h"
#include <iostream>
#include <Jeu.h>

PreteurSurGages::PreteurSurGages(){
    nom = "Preteur sur gages";
    cout = 4;
    description = "Vouz pouvez écarter un Cuivre de votre main pour +3 pieces;";
}

void PreteurSurGages::effet(Joueur* j){
    bool continuer = false;
    for(Carte* cartePtr : j->getMain()){
        Cuivre* cPtr = dynamic_cast<Cuivre*>(cartePtr);
        if(cPtr){
            continuer = true;
        }
    }
    if(continuer){
        std::cout<<"Voulez-vous écarter une carte Cuivre ?\n";
        if(Jeu::OuiNon()){
            j->ecarter("Cuivre");
            j->addNbPiece(3);
        }
    }else{
        std::cout<<"Vous n'avez pas de carte Cuivre à écarter.\n";
    }
}