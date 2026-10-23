#include "Bucheron.h"

Bucheron::Bucheron(){
    nom = "Bucheron";
    cout = 3;
    description = "+1 achat, +2 pieces;";
}

void Bucheron::effet(Joueur j){
    j.addNbAchat(1);
    j.addNbPiece(2);
}