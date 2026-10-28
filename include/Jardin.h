#ifndef JARDIN_H
#define JARDIN_H
#include "Victoire.h"

class Jardin : public Victoire {
public:
    Jardin();
    Carte* dupliquer() const override{return new Jardin();}
};
#endif