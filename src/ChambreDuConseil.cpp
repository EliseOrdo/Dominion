#include "ChambreDuConseil.h"
#include "Jeu.h"

ChambreDuConseil::ChambreDuConseil(){
    nom = "ChambreDuConseil";
    cout = 5;
    description = "+4 Cartes,+1 Achat,Tous vos adversaires piochent une carte.;";
}

void ChambreDuConseil::effet(Joueur j){
    j.piocher(4);
    j.addNbAchat(1);
    for(Joueur adv:Jeu::getJoueurs(j)){
        adv.piocher(1);
    }
}