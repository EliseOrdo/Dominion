#ifndef JEU_H
#define JEU_H
#include "Carte.h"
#include "Joueur.h"
#include <map>
#include <vector>
#include <string>
class Jeu {
    static std::map<Carte*,int> pioches;
    static std::vector<Joueur> joueurs;
    static int nb_pioches_vides;
public:
    static Carte* choisirCarte(std::vector<Carte*> listeCartes);
    static bool enleverCarte(std::string nom);
    Carte* getCarte(std::string nom);
    Joueur victoire();
};

#endif