#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Action.h"

class Aventurier: public Action{
public:
    Aventurier();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Aventurier();}
};

#endif