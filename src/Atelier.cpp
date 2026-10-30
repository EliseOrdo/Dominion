#include "Atelier.h"
#include "Jeu.h"

Atelier::Atelier(){
    nom = "Atelier";
    cout = 3;
    description = "Gagne une carte coutant jusqu'à 4";
}

void Atelier::effet(Joueur* j){
    Carte* choix = Jeu::choisirCarte(Jeu::getListeCartesPiochesCoutMax(4));
    if(choix){
        j->Carte2Defausse(Jeu::prendreCartePioches(choix));
    }
    j->ecarter_en_jeu(nom);
}