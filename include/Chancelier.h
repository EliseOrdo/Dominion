#ifndef CHANCELIER_H
#define CHANCELIER_H
#include "Action.h"

class Chancelier: public Action{
public:
    Chancelier();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Chancelier();}
};

#endif