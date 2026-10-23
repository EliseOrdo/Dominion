#ifndef BUCHERON_H
#define BUCHERON_H
#include "Royaume.h"

class Bucheron : virtual Royaume {
public:
    void effet(Joueur j) override;
};

#endif