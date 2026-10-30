#ifndef ESPION_H
#define ESPION_H
#include "Royaume.h"
#include "Attaque.h"

class Espion : public virtual Royaume, public virtual Attaque {
public:
    Espion();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Espion();}
};

#endif