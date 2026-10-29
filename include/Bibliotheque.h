#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include "Royaume.h"

class Bibliotheque : public Royaume{
public:
    Bibliotheque();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Bibliotheque();}
};

#endif