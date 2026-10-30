#include "SalleDuTrone.h"
#include <iostream>
#include "Jeu.h"

SalleDuTrone::SalleDuTrone(){
    nom = "Salle du trône";
    cout = 4;
    description = "Vous pouvez jouer une carte Action de votre main deux fois.;";
}

void SalleDuTrone::effet(Joueur* j){
    std::vector<Carte*> lc = Joueur::getCartesAction(j->getMain());
    std::cout<<"Voulez-vous jouer une carte Action 2 fois ?\n";
    if(Jeu::OuiNon()){
        Carte * c = Jeu::choisirCarte(lc);
        Action* royPtr = dynamic_cast<Action*>(c);
        royPtr->effet(j);
        royPtr->effet(j);
    }
}