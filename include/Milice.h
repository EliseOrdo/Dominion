#ifndef MILICE_H
#define MILICE_H
#include "Action.h"
#include "Attaque.h"

class Milice : protected virtual Action, protected virtual Attaque{
public:
    Milice();
    Carte* dupliquer() const override{return new Milice();}
    void effet(Joueur j) override;
};

#endif