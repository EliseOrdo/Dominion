#ifndef RENO_H
#define RENO_H
#include "Action.h"

class Renovation: public Action {
public:
    Renovation();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Renovation();}
};

#endif