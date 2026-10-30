#ifndef DOUVE_H
#define DOUVE_H
#include "Royaume.h"
#include "Reaction.h"

class Douve : virtual Royaume, virtual Reaction {
public:
    Douve();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Douve();}
};

#endif