#ifndef FESTIN_H
#define FESTIN_H
#include "Action.h"

class Festin : public Action {
public:
    Festin();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Festin();}
};

#endif