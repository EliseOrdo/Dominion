#ifndef CAVE_H
#define CAVE_H
#include "Action.h"

class Cave: public Action {
public:
    Cave();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Cave();}
};

#endif