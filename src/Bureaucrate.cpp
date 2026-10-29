#include "Bureaucrate.h"
#include "Jeu.h"
#include <iostream>

Bureaucrate::Bureaucrate(){
    nom = "Bureaucrate";
    cout = 4;
    description = "Recevez un Argent sur votre pioche. Tous voz adversaires dévoilent une carte Victoire de leur main et la placent sur leur pioche (ou dévoilent une main sans carte Victoire).;";
}

void Bureaucrate::effet(Joueur j){
    j.Carte2Deck(Jeu::prendreCartePioches("Argent"));
    std::vector<Joueur> lj = Jeu::getJoueursAffectes(j);
    for(Joueur adv:lj){
        Carte* c = adv.montrerCarteVictoire();
        if(c==nullptr){
            std::cout<<"Le joueur "<<adv.getId()<<" n'a pas de carte victoire en main. Voici sa main :\n";
            for(Carte* cm:adv.getMain()){
                std::cout<<cm<<std::endl;
            }
        }else{
            std::cout<<"Joueur "<<adv.getId()<<" :\n"<<c<<std::endl;
            adv.Carte2Deck(c);//met la carte dans le deck du joueur concerné
            adv.getMain().erase(adv.getMain().begin()+adv.getIndCarteMain(c->getNom())); //enleve la carte de sa main
        }
    }
}