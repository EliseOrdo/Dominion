#ifndef SORCIERE_H
#define SORCIERE_H
#include "Royaume.h"
#include "Attaque.h"

class Sorciere : public virtual Attaque, public virtual Royaume {
public:
    Sorciere();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Sorciere();}
};

#endif