#ifndef CHANCELIER_H
#define CHANCELIER_H
#include "Royaume.h"

class Chancelier: public Royaume{
public:
    Chancelier();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Chancelier();}
};

#endif