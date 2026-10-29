#ifndef VOLEUR_H
#define VOLEUR_H
#include "Attaque.h"
#include "Action.h"

class Voleur : public virtual Attaque, public virtual Action {
public:
    Voleur();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Voleur();}
};

#endif