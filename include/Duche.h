#ifndef Duche_H
#define Duche_H
#include "Victoire.h"

class Duche : public Victoire{
    public:
        Duche();
        Carte* dupliquer() const override{return new Duche();}

};

#endif