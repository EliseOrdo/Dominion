#include "Jeu.h"
#include "Domaine.h"
#include "Cuivre.h"
#include <iostream>
#include <limits>
#include <string>
#include <Reaction.h>
#include <iostream>

std::map<Carte*, int> Jeu::pioches;
std::vector<Joueur> Jeu::joueurs;
int Jeu::nb_pioches_vides = 0;

void Jeu::config(){
    //Nombre de joueurs
    int rep;
    std::cout<<"Combien de joueurs (entre 2 et 4) ?\n";
    while(!(std::cin>>rep) or rep<2 or 4<rep){
        std::cin.clear();//efface les bits d'erreur du buffer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// supprime la ligne erronée pour eviter boucle infinie
        std::cout<<"erreur, veuillez réessayer.\n";
    }
    joueurs = {};
    for(int i=0; i<rep; i++){
        joueurs.push_back(Joueur());
    }

    for (Joueur j:joueurs){
        for(int i = 0; i<3; i++){
            Domaine* d = new Domaine();
            j.Carte2Defausse(d);
        }
        for(int i = 0; i<7; i++){
            Cuivre* c = new Cuivre();
            j.Carte2Defausse(c);
        }
        j.piocher(5);
    }

    //Partie rapide ou non
    std::string choix;
    do{
        std::cout<<"Choisir mode de partie : \n r : partie rapide \n n : partie normale\n";
        std::cin>>choix;
    }while(choix!="r" || choix!="n");
    if(choix == "r"){
        //initier partie rapide
    }
    if(choix == "n"){
        //initier partie
        int nb_cuivre = 60 - joueurs.size()*7;
    }
    //URGENT : SE CONCENTRER SUR LE MINIMUM POUR LE RAPPORT, CHOISIR NOUS MEME DANS LE CODE LES 10 CARTES ROYAUMES


    //Détermination des cartes à acheter 
    //"Les dix cartes royaumes peuvent être sélectionnées au début, soit parmi plusieurs sets de base, soit nominativement, soit aléatoirement"
    //10 exemplaires de chaque carte royaume et 12 pour jardin
    //Si 2 joueurs : 8 domaines, 8 duchés, 8 provinces 
    //Si 3 à 4 : 12
    //Malédiction : 2 joueurs -> 10; 3 joueurs -> 20; 4 joueurs -> 30
    //60 cuivres (auxquelles on enlève celles que l'on a donné au début)
    //j'arrive pas a dormir donc je continu sur tel (verifie un peu ces lignes)

    //40 argent
    //30 or
}

void Jeu::tour(){
    //alterner entre les joueurs
    //Vérifier que la partie n'est pas finie
}

Carte* Jeu::choisirCarte(std::vector<Carte*> listeCartes){
    for(int i=0; i<int(listeCartes.size());i++){
        std::cout<<i<<": \n"<<listeCartes.at(i)<<std::endl;
    }
    //bool retry = false;
    int rep;
    std::cout<<"quel est votre choix ?\n";
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

Joueur Jeu::victoire(){
    int score_max = -1000; //Pas 0 car les malefices existent
    Joueur gagnant;
    for (Joueur j:joueurs){
        int score = j.getScore();
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

std::vector<Joueur> Jeu::getJoueurs(Joueur j){
    std::vector<Joueur> res = {};
    for (Joueur j2:Jeu::joueurs){
        if(j.getId() != j2.getId()){
            res.push_back(j2);
        }
    }
    return res;
}

std::vector<Joueur> Jeu::getJoueursAffectes(Joueur j){
    std::vector<Joueur> res = {};
    for (Joueur j2:Jeu::joueurs){
        if(j.getId() != j2.getId()){
            bool affect = true;
            for(Carte* c:j2.getMain()){
                Reaction* reactPtr = dynamic_cast<Reaction*>(c);
                if(reactPtr){
                    std::cout<<"vous pouvez réagir avec cette carte :\n"<<c<<"\nSouhaitez-vous la révéler ?\n";
                    if(OuiNon()){
                        if(c->getNom() == "Douve"){
                            affect = false;
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
        if(pair.first->getCout()<cout_max){
            res.push_back(pair.first);
        }
    }
    return res;
}