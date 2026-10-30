#ifndef MILICE_H
#define MILICE_H
#include "Attaque.h"

class Milice : public virtual Attaque{
public:
    Milice();
    Carte* dupliquer() const override{return new Milice();}
    void effet(Joueur* j) override;
};

#endif