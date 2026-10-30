#include "Espion.h"
#include "Jeu.h"
#include <iostream>

Espion::Espion(){
    nom = "Espion";
    cout = 4;
    description = "+1 Carte, +1 Action, tous les joueurs révèlent la premiere carte de leur deck et vous choisissez pou chacun s'il la repose ou la défausse;";
}

void Espion::effet(Joueur* j){
    j->piocher(1);
    j->addNbAction(1);
    std::vector<Joueur*> lj = Jeu::getJoueursAffectes(j);
    for(Joueur* adv:lj){
        Carte* c = j->reveler();
        std::cout<<"Le joueur "<<adv->getId()<<"révèle la carte :\n"<<c;
        std::cout<<"La défausser ?\n";
        if(Jeu::OuiNon()){
            adv->defausser(c);
        }else{
            adv->Carte2Main(c);
        }
    }
}