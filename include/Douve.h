#ifndef DOUVE_H
#define DOUVE_H
#include "Attaque.h"
#include "Reaction.h"

class Douve : virtual Attaque, virtual Reaction {
public:
    void effet(Joueur j) override{j.piocher(2);};
};

#endif