#include <random>
#include <iostream>
#include "Joueur.h"
#include "Cuivre.h"
#include "Jeu.h"
#include "Bucheron.h"

int main(){
    Jeu::config();
    while(Jeu::tour()){};
    //fin de partie
    std::cout<<"La partie est finie !\nCalcul du gagnant...\n";
    std::cout<<"Le joueur "<<Jeu::victoire()->getId()<<" est victorieux ! Bravo !\n";
    Jeu::fin();
    return 0;
}