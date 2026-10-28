#ifndef ARGENT_H
#define ARGENT_H
#include "Tresor.h"
class Argent: public Tresor {
public:
    Argent();
    Carte* dupliquer() const override{return new Argent();}
};

#endif