#ifndef CAVE_H
#define CAVE_H
#include "Royaume.h"

class Cave: public Royaume {
public:
    Cave();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Cave();}
};

#endif