#include "Joueur.h"
#include "Tresor.h"
#include "Victoire.h"
#include "Malediction.h"
#include "Carte.h"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iostream>


std::vector<Carte*> Joueur::getCartesTresor(std::vector<Carte*> listeCartes){
    std::vector<Carte*> res;
    for(Carte* cartePtr : listeCartes){
        Tresor* tresorPtr = dynamic_cast<Tresor*>(cartePtr);
        if(tresorPtr){
            res.push_back(cartePtr);
        }
    }
    return res;
}

Joueur::Joueur(){
    nb_action = 1;
    nb_piece = 0;
    nb_achat = 1;
}

void Joueur::melanger(){
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(defausse.begin(), defausse.end(), g);
    deck = defausse;
    defausse = {};
}

Carte* Joueur::reveler(){
    if (deck.size()==0){
        melanger();
    }
    Carte* rev = deck[deck.size()-1];
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
    /*retourne l'indice de la premiere instance de carte dans la main ou une erreur si elle n'y est pas*/
    for(int i=0; i<int(main.size());i++){
        if(main.at(i)->getNom()==nom){
            return i;
        }
    }
    throw std::invalid_argument("la carte n'est pas dans la main");
}

void Joueur::ecarter(std::string nom){
    /*détruit la carte de la main*/
    try{
        Carte* c = main.at(getIndCarteMain(nom));
        main.erase(main.begin()+getIndCarteMain(nom)); //erase prend un iterator, d'où le begin()
        delete c;
    }
    catch (std::invalid_argument& e){
        std::cerr<< e.what()<<"\n";
    }
    
}

void Joueur::finDeTour(){
    nb_action = 1;
    nb_piece = 0;
    nb_achat = 1;

    for(Carte*carte:main){
        defausse.push_back(carte);
    }
    main = {};
    piocher(5);
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

std::vector<Carte*> Joueur::getMain(){
    return main;
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

void Joueur::recevoirCarte(Carte* carte){
    /*met la carte dans la main du joueur, pensée pour être appelée avec Jeu::enleverCarte()*/
    main.push_back(carte);
}

int Joueur::getScore(){
    int score = 0;
    deck.insert(deck.end(), main.begin(), main.end());
    deck.insert(deck.end(), defausse.begin(), defausse.end());
    main = {};
    defausse = {};
    for(Carte* carte : deck){
        Victoire* vict = dynamic_cast<Victoire*>(carte);
        if(vict){
            score += vict->get_points();
        }else{
            Malediction* mal = dynamic_cast<Malediction*>(carte);
            if(mal){
                score -= 1;
            }
        }
    }
    return score;
}

/*
TODO ? but : enlever une carte d'une liste de carte

Carte* Joueur::enleverCarte(std::string nom, std::vector<Carte*> liste){
    for(Carte* c : liste){
        if(c->getNom()==nom){
            liste.
            return c;
        }
    }
}*/