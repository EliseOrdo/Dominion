#ifndef PRET_H
#define PRET_H
#include "Royaume.h"
class PreteurSurGages: public Royaume {
public:
    PreteurSurGages();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new PreteurSurGages();}
};

#endif