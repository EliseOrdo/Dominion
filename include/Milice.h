#ifndef MILICE_H
#define MILICE_H
#include "Royaume.h"
#include "Attaque.h"

class Milice : public virtual Royaume, public virtual Attaque{
public:
    Milice();
    Carte* dupliquer() const override{return new Milice();}
    void effet(Joueur* j) override;
};

#endif