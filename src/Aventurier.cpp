#include "Aventurier.h"
#include <Tresor.h>
#include <iostream>

Aventurier::Aventurier(){
    nom = "Aventurier";
    cout = 6;
    description = "Dévoilez des cartes de votre deck jusqu'à ce que 2 cartes Trésor soient dévoilées. Ajoutez ces cartes Trésor à votre main et défaussez les autres cartes dévoilées.;";
}

void Aventurier::effet(Joueur* j){
    std::vector<Carte*> l,tres;
    bool continuer = true;
    while(continuer){
        Carte* c = j->reveler();
        std::cout<<c<<std::endl;
        Tresor* tresorPtr = dynamic_cast<Tresor*>(c);
        if(tresorPtr){
            tres.push_back(c);
            if(tres.size()==2 or (j->getDeck().size()==0 and j->getDefausse().size()==0)){
                continuer = false;
            }
        }else{
            l.push_back(c);
        }
    }
    for(Carte* t:tres){
        j->Carte2Main(t);
    }
    for(Carte* c:l){
        j->defausser(c);
    }
}