#ifndef FESTIVAL_H
#define FESTIVAL_H
#include "Royaume.h"

class Festival: public Royaume{
public:
    Festival();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Festival();}
};

#endif