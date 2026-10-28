#ifndef CUIVRE_H
#define CUIVRE_H
#include "Tresor.h"
class Cuivre: public Tresor {
public:
    Cuivre();
    Carte* dupliquer() const override{return new Cuivre();}
};

#endif