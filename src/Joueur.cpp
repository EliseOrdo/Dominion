#include "Joueur.h"
#include <random>
#include <algorithm>

void Joueur::melanger(){
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(defausse.begin(), defausse.end(), g);
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

void Joueur::piocher(int nb){
    for(int i=0;i<nb;i++){
        if (deck.size()==0){
            melanger();
        }
        main.push_back(deck[deck.size()-1]);
        deck.pop_back();
    }
}

int Joueur::getNbAction(){
    return nb_action;
}

int Joueur::getNbAchat(){
    return nb_achat;
}

int Joueur::getNbPiece(){
    return nb_piece;
}

void Joueur::addNbAction(int nb){
    nb_action += nb;
}

void Joueur::addNbAchat(int nb){
    nb_achat += nb;
}

void Joueur::addNbPiece(int nb){
    nb_piece += nb;
}