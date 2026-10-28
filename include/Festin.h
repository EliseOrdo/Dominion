#ifndef FESTIN_H
#define FESTIN_H
#include "Royaume.h"

class Festin : public Royaume {
public:
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Festin();}
};

#endif