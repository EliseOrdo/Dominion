#include "Laboratoire.h"
#include "Joueur.h"

Laboratoire::Laboratoire(){
    nom = "Laboratoire";
    cout = 5;
    description = "+2 Cartes, +1 Action;";
}

void Laboratoire::effet(Joueur* j){
    j->addNbAction(1);
    j->piocher(2);
}