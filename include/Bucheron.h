#ifndef BUCHERON_H
#define BUCHERON_H
#include "Royaume.h"

class Bucheron : public  Royaume {
public:
    Bucheron();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Bucheron();}
};

#endif