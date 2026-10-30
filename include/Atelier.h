#ifndef ATELIER_H
#define ATELIER_H
#include "Royaume.h"

class Atelier: public Royaume{
    public:
        Atelier();
        void effet(Joueur* j) override;
        Carte* dupliquer() const override{return new Atelier();}
};

#endif