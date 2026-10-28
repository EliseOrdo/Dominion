#ifndef DOUVE_H
#define DOUVE_H
#include "Attaque.h"
#include "Reaction.h"

class Douve : virtual Attaque, virtual Reaction {
public:
    Douve();
    void effet(Joueur j) override{j.piocher(2);};
    Carte* dupliquer() const override{return new Douve();}
};

#endif