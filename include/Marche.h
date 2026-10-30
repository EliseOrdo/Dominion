#ifndef MARCHE_H
#define MARCHE_H
#include "Action.h"

class Marche : public Action {
public:
    Marche();
    Carte* dupliquer() const override{return new Marche();}
    void effet(Joueur* j) override;
};

#endif