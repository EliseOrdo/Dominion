#ifndef LABO_H
#define LABO_H
#include "Royaume.h"

class Laboratoire : protected virtual Royaume {
    void effet(Joueur j) override;
};

#endif