#include "Jeu.h"
#include <iostream>
#include <limits>
#include <string>

std::map<Carte*, int> Jeu::pioches;
std::vector<Joueur> Jeu::joueurs;
int Jeu::nb_pioches_vides = 0;

Carte* Jeu::choisirCarte(std::vector<Carte*> listeCartes){
    std::cout<<"-1 : Ne rien prendre"<<std::endl;
    for(int i=0; i<int(listeCartes.size());i++){
        std::cout<<i<<": \n"<<listeCartes.at(i)<<std::endl;
    }
    //bool retry = false;
    int rep;
    std::cout<<"quel est votre choix ?\n";
    while(!(std::cin>>rep) or rep<-1 or int(listeCartes.size())<rep){
        if(rep == -1){return nullptr;}
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

std::vector<Joueur> Jeu::getJoueursAffectes(Joueur j){
    std::vector<Joueur> res = {};
    for (Joueur j2:Jeu::joueurs){
        if(j.getId() != j2.getId()){
            bool affect = true;
            for(Carte* c:j2.getMain()){
                if(c->getNom() == "Douve"){
                    affect = false;
                    break;
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