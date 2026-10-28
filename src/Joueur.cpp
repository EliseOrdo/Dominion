#include "Joueur.h"
#include "Jeu.h"
#include "Tresor.h"
#include "Jardin.h"
#include "Victoire.h"
#include "Malediction.h"
#include "Carte.h"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iostream>

int Joueur::dernier_id = -1;

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
    dernier_id += 1;
    id = dernier_id;
    nb_action = 1;
    nb_piece = 0;
    nb_achat = 1;
}

void Joueur::achat(){
    /*Ne vérifie pas que le joueur peurt acheter*/
    //Calcule l'argent
    for(Carte* c:main){
        Tresor* tres = dynamic_cast<Tresor*>(c);
        if(tres){
            nb_piece += tres->getCout();
        }
    }

    //Affiche les possibilitées et achète
    std::vector<Carte*> liste_carte = Jeu::getListeCartesPiochesCoutMax(nb_piece);
    for (Carte* c: liste_carte){
        std::cout<<c<<std::endl;
    }
    std::cout<<"Voulez-vous acheter ? \n";
    if(Jeu::OuiNon()){
        Carte* choix = Jeu::choisirCarte(Jeu::getListeCartesPiochesCoutMax(nb_piece));
        if(choix){
            Joueur::prendreCarte(Jeu::prendreCartePioches(choix));
            nb_achat -=1;
            nb_piece -= choix->getCout();
        }
    }
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

int Joueur::getId(){
    return id;
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
    /*met la carte dans la main du joueur*/
    main.push_back(carte);
}

void Joueur::prendreCarte(Carte* carte){
    /*met la carte dans la main du joueur*/
    defausse.push_back(carte);
}

int Joueur::getScore(){
    int score = 0;
    deck.insert(deck.end(), main.begin(), main.end());
    deck.insert(deck.end(), defausse.begin(), defausse.end());
    main = {};
    defausse = {};
    for(Carte* carte : deck){
        Jardin* jard = dynamic_cast<Jardin*>(carte);
        if(jard){
            score += deck.size()/10;
        }else{
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
    }
    return score;
}

