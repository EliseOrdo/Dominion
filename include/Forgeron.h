#ifndef FORGERON_H
#define FORGERON_H
#include "Royaume.h"

class Forgeron: public Royaume{
public:
    Forgeron();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Forgeron();}
};

#endif