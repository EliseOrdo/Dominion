#ifndef Domaine_H
#define Domaine_H
#include "Victoire.h"

class Domaine : public Victoire{
    protected:
        int points;
    
    public:
        Domaine();
        int get_points(){return points;};
        Carte* dupliquer() const override{return new Domaine();}

};

#endif