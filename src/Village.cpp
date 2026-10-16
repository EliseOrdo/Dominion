#include "Village.h"

Village::Village(){
    nom = "Village";
    cout = 3;
    description = "+1 Carte, +2 Action;";
}

void Village::effet(Joueur j){
    j.addNbAction(2);
    j.piocher(1);
}