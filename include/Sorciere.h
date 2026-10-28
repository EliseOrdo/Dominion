#ifndef SORCIERE_H
#define SORCIERE_H
#include "Attaque.h"

class Sorciere : public Attaque {
public:
    Sorciere();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Sorciere();}
};

#endif