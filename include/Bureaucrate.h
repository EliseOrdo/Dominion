#ifndef BUREAUCRATE_H
#define BUREAUCRATE_H
#include "Action.h"
#include "Attaque.h"

class Bureaucrate: public virtual Action, public virtual Attaque{
public:
    Bureaucrate();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Bureaucrate();}
};

#endif