#include "Bibliotheque.h"
#include <iostream>
#include <Jeu.h>

Bibliotheque::Bibliotheque(){
    nom = "Bibliotheque";
    cout = 5;
    description = "Piochez jusqu'à ce que vous ayez 7 cartes en main. Chaque carte Royaume piochée peut être mise de côté. Défaussez les cartes mises de côté lorsque vous avez terminé de piocher.;";
}

void Bibliotheque::effet(Joueur* j){
    std::vector<Carte*> cote;
    while(j->getMain().size()<7){
        j->piocher(1);
        Carte* c = j->getMain().back();
        Royaume* actPtr = dynamic_cast<Royaume*>(c);
        if(actPtr){
            std::cout<<"Voulez-vous mettre la carte suivante de côté ?\n"<<c<<std::endl;
            if(Jeu::OuiNon()){
                j->getMain().pop_back();
                cote.push_back(c);
            }
        }
    }
    std::cout<<"Fin: vous avez 7 cartes en main.\n";
    for(Carte* c:cote){
        j->defausser(c);
    }
}