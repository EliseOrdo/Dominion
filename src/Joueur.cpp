#include "Joueur.h"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iostream>

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

int Joueur::getIndCarteMain(std::string nom){
    /*retourne l'indice de la carte dans la main ou une erreur si elle n'y est pas*/
    for(int i=0; i<main.size();i++){
        if(main.at(i).getNom()==nom){
            return i;
        }
    }
    throw std::invalid_argument("la carte n'est pas dans la main");
}

void Joueur::ecarter(std::string nom){
    /*détruit la carte de la main*/
    try{
        main.erase(main.begin()+getIndCarteMain(nom)); //erase prend un iterator, d'où le begin()
    }
    catch (std::invalid_argument& e){
        std::cerr<< e.what()<<"\n";
    }
    
}

void Joueur::finDeTour(){
    nb_action = 1;
    nb_piece = 0;
    nb_achat = 1;
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