#ifndef VOLEUR_H
#define VOLEUR_H
#include "Attaque.h"


class Voleur : public virtual Attaque{
public:
    Voleur();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Voleur();}
};

#endif