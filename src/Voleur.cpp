#include "Voleur.h"
#include "Tresor.h"
#include "Jeu.h"
#include <iostream>

Voleur::Voleur(){
    nom = "Voleur";
    cout = 4;
    description = "Tous vos adversaires dévoilent les 2 premières cartes de leur deck. S’ils dévoilent des cartes Trésor, ilsen écartent une de votre choix. Parmi les cartes ainsi écartées, vous pouvez récupérer celles de votre choix.";
}

void Voleur::effet(Joueur* j){
    std::map<int, std::vector<Carte*>> cartes_joueurs;
    for(Joueur* j2:Jeu::getJoueursAffectes(j)){
        Carte* c1 = j2->reveler();
        Carte* c2 = j2->reveler();
        Carte* c;
        cartes_joueurs[j2->getId()] = {c1, c2};
        std::vector<Carte*>tres_joueur = Joueur::getCartesTresor(cartes_joueurs.at(j2->getId()));
        if(tres_joueur.size()>1){
            std::cout<<"Le joueur "<<j2->getId()<<" révèle 2 cartes Trésor :\n";
            c = Jeu::choisirCarte(tres_joueur);
        }else if(tres_joueur.size()==1){
            std::cout<<"Le joueur "<<j2->getId()<<" révèle 1 carte Trésor :\n"<<tres_joueur.at(0);
            c= tres_joueur.at(0);
        }else{
            std::cout<<"Le joueur "<<j2->getId()<<" ne révèle pas de carte Trésor\n";
            c = nullptr;
        }
        if(c!= nullptr and c->getNom() == c1->getNom()){
            j2->Carte2Defausse(c2);
            std::cout<<"Voulez-vous prendre cette carte dans votre défausse (o) ou la mettre au rebus (n) ?\n";
            if(Jeu::OuiNon()){
                j->Carte2Defausse(c1);
            }else{
                delete c1;
            }
        }else if(c!= nullptr and c->getNom() == c2->getNom()){
            j2->Carte2Defausse(c1);
            std::cout<<"Voulez-vous prendre cette carte dans votre défausse (o) ou la mettre au rebus (n) ?\n";
            if(Jeu::OuiNon()){
                j->Carte2Defausse(c2);
            }else{
                delete c2;
            }
        }
    }
}