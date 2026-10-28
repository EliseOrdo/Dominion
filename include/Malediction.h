#ifndef MALED_H
#define MALED_H
#include "Carte.h"
class Malediction : public Carte {
public:
    Malediction();
    Carte* dupliquer() const override{return new Malediction();}
};

#endif