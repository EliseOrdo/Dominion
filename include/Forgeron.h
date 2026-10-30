#ifndef FORGERON_H
#define FORGERON_H
#include "Action.h"

class Forgeron: public Action{
public:
    Forgeron();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Forgeron();}
};

#endif