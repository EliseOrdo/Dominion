#ifndef SORCIERE_H
#define SORCIERE_H
#include "Action.h"
#include "Attaque.h"

class Sorciere : public virtual Attaque, public virtual Action {
public:
    Sorciere();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Sorciere();}
};

#endif