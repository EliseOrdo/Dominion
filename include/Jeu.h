#ifndef JEU_H
#define JEU_H
#include "Carte.h"
#include "Joueur.h"
#include <map>
#include <vector>
class Jeu {
    std::map<Carte,int> pioches;
    std::vector<Joueur> joueurs;
    int nb_pioches_vides;
};

#endif