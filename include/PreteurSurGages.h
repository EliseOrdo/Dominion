#ifndef PRET_H
#define PRET_H
#include "Action.h"

class PreteurSurGages: public Action {
public:
    PreteurSurGages();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new PreteurSurGages();}
};

#endif