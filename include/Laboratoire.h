#ifndef LABO_H
#define LABO_H
#include "Action.h"

class Laboratoire : protected Action {
public:
    Laboratoire();
    Carte* dupliquer() const override{return new Laboratoire();}
    void effet(Joueur* j) override;
};

#endif