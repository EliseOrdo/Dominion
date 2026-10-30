#ifndef Province_H
#define Province_H
#include "Victoire.h"

class Province : public Victoire{
    public:
        Province();
        Carte* dupliquer() const override{return new Province();}
};

#endif