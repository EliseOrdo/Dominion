#include "Forgeron.h"

Forgeron::Forgeron(){
    nom = "Forgeron";
    cout = 4;
    description = "+3 Cartes;";
}

void Forgeron::effet(Joueur* j){
    j->piocher(3);
}