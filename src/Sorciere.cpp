#include "Sorciere.h"
#include "Jeu.h"

Sorciere::Sorciere(){
    nom = "Sorciere";
    cout = 5;
    description = "+2 cartes, chaque autre joueur gagne une malédiction";
}

void Sorciere::effet(Joueur* j){
    j->piocher(2);

    for(Joueur* j2:Jeu::getJoueursAffectes(j)){
        Carte* mal = Jeu::prendreCartePioches("Malediction");
        if(mal){
            j2->Carte2Defausse(mal);
        }
    }
}