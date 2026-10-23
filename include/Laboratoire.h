#ifndef LABO_H
#define LABO_H
#include "Royaume.h"

class Laboratoire : protected virtual Royaume {
public:
    Laboratoire();

    void effet(Joueur j) override;
};

#endif