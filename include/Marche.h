#ifndef MARCHE_H
#define MARCHE_H
#include "Royaume.h"

class Marche : public Royaume {
public:
    Marche();
    Carte* dupliquer() const override{return new Marche();}
    void effet(Joueur* j) override;
};

#endif