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
    static void config();
    static void premierePartie(bool rapide);

    static Carte* choisirCarte(std::vector<Carte*> listeCartes);
    static bool enleverCarte(std::string nom);
    static Carte* enleverCarte(std::string nom, std::vector<Carte*> liste);

    static Carte* prendreCartePioches(std::string nom);
    static Carte* prendreCartePioches(Carte* carte);

    static std::vector<Joueur> getJoueurs(Joueur j);
    static std::vector<Joueur> getJoueursAffectes(Joueur j);

    static std::vector<Carte*> getListeCartesPiochesCoutMax(int cout_max);
    static Joueur victoire();
    static void fin();
    static bool OuiNon();
    
    static void tour();
};

#endif