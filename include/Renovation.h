#ifndef RENO_H
#define RENO_H
#include "Royaume.h"
class Renovation: public Royaume {
public:
    Renovation();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Renovation();}
};

#endif