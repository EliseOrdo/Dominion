#ifndef LABO_H
#define LABO_H
#include "Royaume.h"

class Laboratoire : protected Royaume {
public:
    Laboratoire();
    Carte* dupliquer() const override{return new Laboratoire();}
    void effet(Joueur j) override;
};

#endif