#include "Douve.h"

Douve::Douve(){
    nom = "Douve";
    cout = 2;
    description = "+2 cartes et quand un autre joueur attaque, l'effet ne s'applique pas";
}

void Douve::effet(Joueur* j){
    j->piocher(2);
}

