#ifndef BUCHERON_H
#define BUCHERON_H
#include "Action.h"

class Bucheron : public  Action {
public:
    Bucheron();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Bucheron();}
};

#endif