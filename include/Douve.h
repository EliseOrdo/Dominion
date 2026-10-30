#ifndef DOUVE_H
#define DOUVE_H
#include "Action.h"
#include "Reaction.h"

class Douve : virtual public Reaction, virtual public Action{
public:
    Douve();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Douve();}
};

#endif