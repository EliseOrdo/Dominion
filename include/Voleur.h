#ifndef VOLEUR_H
#define VOLEUR_H
#include "Attaque.h"
#include "Royaume.h"

class Voleur : public virtual Attaque, public virtual Royaume {
public:
    Voleur();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Voleur();}
};

#endif