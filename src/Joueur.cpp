#include "Joueur.h"
#include <random>

void Joueur::melanger(){
    std::random_device rd;
    std::mt19937 g(rd());

    shuffle(defausse.begin(), defausse.end(), g);
    deck = defausse;
    defausse = {};
}