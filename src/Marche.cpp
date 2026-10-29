#include "Marche.h"

Marche::Marche(){
    nom = "Marché";
    cout = 5;
    description = "+1 Carte, +1 Action, +1 Achat, +1 piece;";
}

void Marche::effet(Joueur j){
    j.piocher(1);
    j.addNbAction(1);
    j.addNbAchat(1);
    j.addNbPiece(1);
}