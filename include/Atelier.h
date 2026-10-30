#ifndef ATELIER_H
#define ATELIER_H
#include "Action.h"

class Atelier: public Action{
    public:
        Atelier();
        void effet(Joueur* j) override;
        Carte* dupliquer() const override{return new Atelier();}
};

#endif