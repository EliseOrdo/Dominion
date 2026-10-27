#include "Jeu.h"
#include <iostream>
#include <limits>

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