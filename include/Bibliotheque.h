#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include "Action.h"

class Bibliotheque : public Action{
public:
    Bibliotheque();
    void effet(Joueur j);
    Carte* dupliquer() const override{return new Bibliotheque();}
};

#endif