#ifndef FESTIVAL_H
#define FESTIVAL_H
#include "Action.h"

class Festival: public Action{
public:
    Festival();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Festival();}
};

#endif