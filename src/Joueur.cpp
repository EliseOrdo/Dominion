#include "Joueur.h"
#include "Jeu.h"
#include "Tresor.h"
#include "Jardin.h"
#include "Victoire.h"
#include "Malediction.h"
#include "Royaume.h"
#include "Carte.h"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iostream>

int Joueur::dernier_id = 0;

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

std::vector<Carte*> Joueur::getCartesVictoire(std::vector<Carte*> listeCartes){
    std::vector<Carte*> res;
    for(Carte* cartePtr : listeCartes){
        Victoire* victoirePtr = dynamic_cast<Victoire*>(cartePtr);
        if(victoirePtr){
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

void Joueur::tour(){
    std::cout<<"\nTour du joueur "<<id<<std::endl;
    //phase action
    while(nb_action > 0){
        Joueur::jouerCarte();
    }

    //phase achat
    for(Carte* c:main){
        Tresor* tres = dynamic_cast<Tresor*>(c);
        if(tres){
            nb_piece += tres->getValeur();
        }
    }
    while(nb_achat > 0){
        achat();
    }

    //phase ajustement
    travailTermine();
    std::cout<<"Nouvelle main : \n";
    for (Carte* c:main){
        std::cout<<c<<std::endl;
    }
}

void Joueur::achat(){
    /*Ne vérifie pas que le joueur peut acheter*/

    //Affiche les possibilitées et achète
    std::cout<<"\n\nNombre d'achat restant : "<<nb_achat<<std::endl;
    std::cout<<"Vous avez "<<nb_piece<<" pieces\n";
    std::cout<<"Achats possibles : \n\n";
    std::vector<Carte*> liste_carte = Jeu::getListeCartesPiochesCoutMax(nb_piece);
    for (Carte* c: liste_carte){
        std::cout<<c<<std::endl;
    }
    std::cout<<"Acheter une carte ? \n";
    if(Jeu::OuiNon()){
        Carte* choix = Jeu::choisirCarte(Jeu::getListeCartesPiochesCoutMax(nb_piece));
        if(choix){
            std::cout<<std::endl;
            Joueur::Carte2Defausse(Jeu::prendreCartePioches(choix));
            nb_piece -= choix->getCout();
        }
    }
    nb_achat -=1;
}

void Joueur::jouerCarte(){
    std::cout<<"\nNombre d'action restante : "<<nb_action<<std::endl;
    std::cout<<"Cartes en main : \n";
    std::cout<<std::endl;
    for (Carte*c:main){
        std::cout<<c<<std::endl;
    }
    std::cout<<"Jouer une carte ? \n";
    if(Jeu::OuiNon()){
        Carte* carte;
        Royaume* roy = nullptr;
        do{
            carte = Jeu::choisirCarte(main);
            roy = dynamic_cast<Royaume*>(carte);
        }while(!roy);
        poserCarte(roy);
        roy->effet(this);
    }
    nb_action -= 1;
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
    Carte* rev = deck.at(deck.size()-1);
    deck.pop_back();
    return rev;
}

void Joueur::piocher(int nb){
    std::cout<<"Le joueur "<<id<<" pioche\n";
    for(int i=0;i<nb;i++){
        if (deck.size()==0){
            melanger();
        }
        main.push_back(deck.at(deck.size()-1));
        deck.pop_back();
    }
}

void Joueur::poserCarte(Carte* carte){
    int indice = getIndCarteMain(carte->getNom());
    main.erase(main.begin()+indice);
    en_jeu.push_back(carte);
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

void Joueur::enleverDeMain(std::string nom){
    main.erase(main.begin()+getIndCarteMain(nom));
}

void Joueur::ecarter_en_jeu(std::string nom){
    /*détruit la carte posée*/
    for (size_t i = 0; i < en_jeu.size(); i++){
        Carte* c = en_jeu.at(i); 
        if(c->getNom() == nom){
            en_jeu.erase(en_jeu.begin()+i);
            delete c;
            break;
        }
    }
}

void Joueur::defausser(Carte* carte){
    /*met la carte dans la defausse du joueur !!ne la retire pas de là où elle vient!!*/
    defausse.push_back(carte);
}

void Joueur::travailTermine(){
    nb_action = 1;
    nb_piece = 0;
    nb_achat = 1;

    for(Carte*carte:main){
        defausse.push_back(carte);
    }
    for(Carte*carte:en_jeu){
        defausse.push_back(carte);
    }
    main = {};
    en_jeu = {};
    piocher(5);
}

Carte* Joueur::montrerCarteVictoire(){
    std::vector<Carte*> lv = Joueur::getCartesVictoire(main);
    if(lv.size()>0){
        return Jeu::choisirCarte(lv);
    }else{
        return nullptr;
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

std::vector<Carte*> Joueur::getMain(){
    return main;
}

std::vector<Carte*> Joueur::getDefausse(){
    return defausse;
}

std::vector<Carte*> Joueur::getDeck(){
    return deck;
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

void Joueur::Carte2Main(Carte* carte){
    /*met la carte dans la main du joueur*/
    main.push_back(carte);
}

void Joueur::Carte2Defausse(Carte* carte){
    /*met la carte dans la defausse du joueur*/
    defausse.push_back(carte);
}

void Joueur::Carte2Deck(Carte* carte){
    /*met la carte dans la defausse du joueur*/
    deck.push_back(carte);
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
    
    //suspresions des cartes
    while(deck.size()>0){
        Carte* c = deck.at(deck.size()-1);
        deck.pop_back();
        delete c;
    }
    return score;
}

