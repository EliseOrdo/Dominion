#include "Mine.h"
#include <iostream>
#include "Joueur.h"
#include "Carte.h"
#include "Jeu.h"
#include "Tresor.h"
#include "Argent.h"

Mine::Mine(){
    nom = "Mine";
    cout = 5;
    description = "Ecartez une carte trésor de votre main pour recevoir une carte trésor coutant jusqu'a 3 de plus (ajoutée dans la main);";
}

/*PAS FINI*/
/* void Mine::effet(Joueur j){
    std::vector<Carte*> cartes_tres = Joueur::getCartesTresor(j.getMain());
    std::cout<<"Ecartez une carte Tresor : ";
    Carte* carte = Jeu::choisirCarte(cartes_tres);
    Tresor* tresor = dynamic_cast<Tresor*>(carte);
    switch(tresor->getValeur()){
        case 0:
            Jeu::enleverCarte(new Argent())?j.recevoirCarte(new Argent())://jsp; //à voir si ça reste bien en mémoire
    }
}*/