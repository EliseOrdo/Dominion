#include "Joueur.h"
#include <random>

void Joueur::melanger(){
    std::random_device rd;
    std::mt19937 g(rd());

    shuffle(defausse.begin(), defausse.end(), g);
    deck = defausse;
    defausse = {};
}

Carte Joueur::reveler(){
    if (deck.size()==0){
        melanger();
    }
    Carte rev = deck[deck.size()-1];
    deck.pop_back();
    return rev;
}

void Joueur::piocher(){
    if (deck.size()==0){
        melanger();
    }
    main.push_back(deck[deck.size()-1]);
    deck.pop_back();
}