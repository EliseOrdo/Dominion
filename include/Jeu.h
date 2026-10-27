#ifndef JEU_H
#define JEU_H
#include "Carte.h"
#include "Joueur.h"
#include <map>
#include <vector>
#include <string>
class Jeu {
    std::map<Carte,int> pioches;
    std::vector<Joueur> joueurs;
    int nb_pioches_vides;
public:
    static Carte* choisirCarte(std::vector<Carte*> listeCartes);
    static Carte* enleverCarte(std::string nom, std::vector<Carte*> liste);
};

#endif