#include "Festin.h"
#include "Jeu.h"

Festin::Festin(){
    nom = "Festin";
    cout = 4;
    description = "Ecarte cette carte, le joueur recoit une carte coutant jusqu'a 5;";
}

void Festin::effet(Joueur j){
    j.ecarter(nom);
    j.Carte2Defausse(Jeu::prendreCartePioches(Jeu::choisirCarte(Jeu::getListeCartesPiochesCoutMax(5))));
}