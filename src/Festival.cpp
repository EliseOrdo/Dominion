#include "Festival.h"

Festival::Festival(){
    nom = "Festival";
    cout = 5;
    description = "+2 actions, +1 achat, +2 pieces;";
}

void Festival::effet(Joueur j){
    j.addNbAction(2);
    j.addNbAchat(1);
    j.addNbPiece(2);
}