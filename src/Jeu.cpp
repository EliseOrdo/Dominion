#include "Jeu.h"
#include "Domaine.h"
#include "Duche.h"
#include "Province.h"
#include "Cuivre.h"
#include "Argent.h"
#include "Or.h"
#include "Malediction.h"
#include "Atelier.h"
#include "Bucheron.h"
#include "Cave.h"
#include "Douve.h"
#include "Forgeron.h"
#include "Marche.h"
#include "Milice.h"
#include "Mine.h"
#include "Festin.h"
#include "Renovation.h"
#include "Village.h"
#include "Aventurier.h"
#include "Bureaucrate.h"
#include "Chancelier.h"
#include "Chapelle.h"
#include "Laboratoire.h"
#include "PreteurSurGages.h"
#include "SalleDuTrone.h"
#include "Bibliotheque.h"
#include "ChambreDuConseil.h"
#include "Espion.h"
#include "Festival.h"
#include "Voleur.h"
#include "Jardin.h"
#include "Sorciere.h"
#include <iostream>
#include <limits>
#include <string>
#include <Reaction.h>
#include <iostream>

std::map<Carte*, int> Jeu::pioches;
std::vector<Joueur*> Jeu::joueurs;
int Jeu::nb_pioches_vides = 0;
std::vector<Carte*> cartes_premieres_parties = {new Atelier(), new Bucheron(), new Cave(), new Douve(), new Forgeron(), new Marche(), new Milice(), new Mine(), new Renovation(), new Village()};
std::vector<Carte*> cartes_richesses_et_tresors = {new Aventurier(), new Bureaucrate(), new Chancelier(), new Chapelle(), new Festin(), new Laboratoire(), new Marche(), new Mine(), new PreteurSurGages(), new SalleDuTrone()};
std::vector<Carte*> cartes_interaction = {new Bibliotheque(), new Bureaucrate(), new ChambreDuConseil(), new Chancelier(), new Douve(), new Espion(), new Festival(), new Milice(), new Village(), new Voleur()};
std::vector<Carte*> cartes_changement_de_taille = {new Atelier(), new Bucheron(), new Cave(), new Chapelle(), new Festin(), new Jardin(), new Laboratoire(), new Sorciere(), new Village(), new Voleur()};
std::vector<Carte*> cartes_place_du_village = {new Bibliotheque(), new Bucheron(), new Bureaucrate(), new Cave(), new Festival(), new Forgeron(), new Marche(), new Renovation(), new SalleDuTrone(), new Village()};
std::vector<Carte*> cartes_depart;

void choix_depart(){
    std::cout<<"Quel ensemble choisissez vous ? (premieres parties: 0, richesses et tresors: 1, interaction: 2, changement taille : 3, place du village : 4\n";
    int rep;
    while(!(std::cin>>rep) or rep<0 or 4<rep){
        std::cin.clear();//efface les bits d'erreur du buffer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// supprime la ligne erronée pour eviter boucle infinie
        std::cout<<"erreur, veuillez réessayer.\n";
    }
    switch(rep){
        case 0:
            cartes_depart = cartes_premieres_parties;
            break;
        case 1:
            cartes_depart = cartes_richesses_et_tresors;
            break;
        case 2:
            cartes_depart = cartes_interaction;
            break;
        case 3:
            cartes_depart = cartes_changement_de_taille;
            break;
        case 4:
            cartes_depart = cartes_place_du_village;
            break;
    }
}

void Jeu::config(){
    //choix cartes
    choix_depart();
    //Nombre de joueurs
    int rep;
    std::cout<<"\nCombien de joueurs (entre 2 et 4) ?\n";
    while(!(std::cin>>rep) or rep<2 or 4<rep){
        std::cin.clear();//efface les bits d'erreur du buffer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// supprime la ligne erronée pour eviter boucle infinie
        std::cout<<"erreur, veuillez réessayer.\n";
    }
    joueurs = {};
    for(int i=0; i<rep; i++){
        joueurs.push_back(new Joueur());
    }

    for (Joueur* j:joueurs){
        for(int i = 0; i<3; i++){
            Domaine* d = new Domaine();
            j->Carte2Defausse(d);
        }
        for(int i = 0; i<7; i++){
            Cuivre* c = new Cuivre();
            j->Carte2Defausse(c);
        }
        j->piocher(5);
    }

    //Partie rapide ou non
    std::string choix;
    do{
        std::cout<<"\n\nChoisir mode de partie : \n r : partie rapide \n n : partie normale\n";
        std::cin>>choix;
    }while(choix!="r" and choix!="n");
    if(choix == "r"){
        //initier partie rapide
        pioches[new Cuivre()] = 1;
        pioches[new Argent()] = 1;
        pioches[new Or()] = 1;
        pioches[new Malediction()] = 1;
        pioches[new Domaine()] = 1;
        pioches[new Duche()] = 1;
        pioches[new Province()] = 1;
        Jeu::premierePartie(true);
    }
    if(choix == "n"){
        //initier partie
        //Reste le meme pour tt config
        pioches[new Cuivre()] = 60 - joueurs.size()*7;
        pioches[new Argent()] = 40;
        pioches[new Or()] = 30;
        pioches[new Malediction()] = (joueurs.size()-1)*10;
        if(joueurs.size()==2){
            pioches[new Domaine()] = 8;
            pioches[new Duche()] = 8;
            pioches[new Province()] = 8;
        }else{
            pioches[new Domaine()] = 12;
            pioches[new Duche()] = 12;
            pioches[new Province()] = 12;
        }
        //Config "Première partie"
        Jeu::premierePartie(false);
    }

    //Détermination des cartes à acheter 
    //"Les dix cartes royaumes peuvent être sélectionnées au début, soit parmi plusieurs sets de base, soit nominativement, soit aléatoirement"
    //10 exemplaires de chaque carte royaume et 12 pour jardin


}

void Jeu::premierePartie(bool rapide){
    int nb = 10;
    if(rapide){nb = 1;}
    for(Carte* c:cartes_depart){
        pioches[c->dupliquer()] = nb;
    }
}

bool Jeu::tour(){
    //alterner entre les joueurs
    //Vérifier que la partie n'est pas finie
    for(Joueur* j:joueurs){
        j->tour();
        int nb_prov;
        for(auto pair:pioches){
            if(pair.first->getNom()=="Province"){
                nb_prov = pair.second;
            }
        }
        if(nb_pioches_vides>= 3 or nb_prov==0){
            return false;
        }
    }return true;
}

Carte* Jeu::choisirCarte(std::vector<Carte*> listeCartes){
    std::cout<<std::endl;
    for(int i=0; i<int(listeCartes.size());i++){
        std::cout<<i<<": \n"<<listeCartes.at(i)<<std::endl;
    }
    //bool retry = false;
    int rep;
    std::cout<<"Quel est votre choix ?\n";
    while(!(std::cin>>rep) or rep<0 or int(listeCartes.size())<rep){
        std::cin.clear();//efface les bits d'erreur du buffer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// supprime la ligne erronée pour eviter boucle infinie
        std::cout<<"erreur, veuillez réessayer.\n";
    }
    
    return listeCartes.at(rep);
}

bool Jeu::OuiNon(){
    bool retry;
    do{
        retry = false;
        std::string rep;
        std::cout<<"o/n : ";
        std::cin>>rep;
        if(rep=="o"){return true;}
        if(rep=="n"){return false;}
        else{retry = true;}
    }while(retry);
    return false;
}

Joueur* Jeu::victoire(){
    int score_max = -1000; //Pas 0 car les malefices existent
    Joueur* gagnant;
    for (Joueur* j:joueurs){
        int score = j->getScore();
        if(score > score_max){
            score_max = score;
            gagnant = j;
        }
    }
    return gagnant;
}

void Jeu::fin(){
    //suprimmer les cartes des pioches
}


Carte* Jeu::prendreCartePioches(std::string nom){
    /*retourne nullptr si ne trouve pas la carte*/
    for(auto pair:pioches){
        if(pair.first->getNom()==nom){
            if(pair.second>0){
                pair.second -= 1;
                if(pair.second==0){
                    nb_pioches_vides += 1;
                }
                return pair.first->dupliquer();
            }
        }
    }
    return nullptr;
}

Carte* Jeu::prendreCartePioches(Carte* carte){
    /*retourne nullptr si ne trouve pas la carte*/
    if(pioches.at(carte)>0){
        pioches.at(carte) -= 1;
        if(pioches.at(carte)==0){
            nb_pioches_vides += 1;
        }
        return carte->dupliquer();
    }
    return nullptr;
}

Carte* Jeu::enleverCarte(std::string nom, std::vector<Carte*> liste){
    for(size_t i=0; i<liste.size(); i++){
        if(liste.at(i)->getNom()==nom){
            liste.erase(liste.begin()+i);
            return liste.at(i);
        }
    }
    return nullptr;
}

std::vector<Joueur*> Jeu::getJoueurs(Joueur* j){
    std::vector<Joueur*> res = {};
    for (Joueur* j2:Jeu::joueurs){
        if(j->getId() != j2->getId()){
            res.push_back(j2);
        }
    }
    return res;
}

std::vector<Joueur*> Jeu::getJoueursAffectes(Joueur* j){
    std::vector<Joueur*> res = {};
    for (Joueur* j2:Jeu::joueurs){
        if(j->getId() != j2->getId()){
            bool affect = true;
            for(Carte* c:j2->getMain()){
                Reaction* reactPtr = dynamic_cast<Reaction*>(c);
                if(reactPtr){
                    std::cout<<"Joueur "<<j2->getId()<< "vous pouvez réagir avec cette carte :\n"<<c<<"\nSouhaitez-vous la révéler ?\n";
                    if(OuiNon()){
                        if(c->getNom() == "Douve"){
                            affect = false;
                            std::cout<<"Joueur "<<j2->getId()<<" a joué Douve, l'effet ne s'applique pas sur lui\n";
                            break;
                        }
                        //effectuer la reaction de la carte
                    }
                }
            }
            if(affect){
                res.push_back(j2);
            }
        }
    }
    return res;
}

std::vector<Carte*> Jeu::getListeCartesPiochesCoutMax(int cout_max){
    std::vector<Carte*> res;
    for(auto pair:pioches){
        if(pair.first->getCout()<=cout_max){
            res.push_back(pair.first);
        }
    }
    return res;
}