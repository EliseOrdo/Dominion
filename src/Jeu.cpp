#include "Jeu.h"
#include <iostream>
#include <limits>
#include <string>

Carte* Jeu::choisirCarte(std::vector<Carte*> listeCartes){
    for(int i=0; i<int(listeCartes.size());i++){
        std::cout<<i<<": "<<listeCartes.at(i)<<std::endl;
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

/*PAS FINI*/
Carte* Jeu::getCarte(std::string nom){
    /*n'enleve pas de carte de la pioche*/
    for(auto pair:pioches){
        if(pair.first->getNom()==nom){
            return pair.first;// TODO faudrait créer une nouvelle carte de même classe
        }
    }
}

/*PAS FINI*/
bool Jeu::enleverCarte(std::string nom){
    /*renvoie true si on a pu enlever une carte de la pioche*/
    if(pioches.at(carte)>0){ //TODO comparer les noms (regarder les autres endroits où on cherche avec les noms)
        pioches.at(carte) -= 1;
        if(pioches.at(carte)==0){
            nb_pioches_vides += 1;
        }
        return true;
    }else{
        return false;
    }
}