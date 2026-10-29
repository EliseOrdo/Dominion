#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Royaume.h"

class Aventurier: public Royaume{
public:
    Aventurier();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Aventurier();}
};

#endif