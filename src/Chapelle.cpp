#include "Chapelle.h"
#include "Jeu.h"
#include <iostream>
#include <algorithm>

Chapelle::Chapelle(){
    nom = "Chapelle";
    cout = 2;
    description = "ecartez jusqu'à 4 cartes de votre main;";
}

void Chapelle::effet(Joueur j){
    int max = std::min(4,int(j.getMain().size()));
    std::cout<<"Souhaitez-vous écarter une carte de votre main ?\n";
    bool continuer = Jeu::OuiNon();
    int cpt = 0;
    while(continuer){
        Carte* c = Jeu::choisirCarte(j.getMain());
        j.ecarter(c->getNom());
        cpt += 1;
        if(cpt<max){
            std::cout<<"Souhaitez-vous écarter une carte de votre main ?\n";
            continuer = Jeu::OuiNon();
        }else{
            continuer = false;
        }
    }
}