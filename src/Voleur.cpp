#include "Voleur.h"
#include "Jeu.h"

Voleur::Voleur(){
    nom = "Voleur";
    cout = 4;
    description = "Tous vos adversaires dévoilent les 2 premières cartes de leur deck. S’ils dévoilent des cartes Trésor, ilsen écartent une de votre choix. Parmi les cartes ainsi écartées, vous pouvez récupérer celles de votre choix.";
}

void Voleur::effet(Joueur j){
    std::map<int, std::vector<Carte*>> cartes_joueurs;
    for(Joueur j2:Jeu::getJoueursAffectes(j)){
        Carte* c1 = j2.reveler();
        Carte* c2 = j2.reveler();
        cartes_joueurs[j2.getId()] = {c1, c2};
    }
    //Ensuite faut faire choisir une carte tresor par joueur et décider si le joueur la prend ou la jette, puis redonner leurs cartes aux joueurs si elle n'a pas été prise ou jetée
}