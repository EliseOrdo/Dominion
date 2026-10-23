#ifndef FESTIN_H
#define FESTIN_H
#include "Royaume.h"

class Festin : virtual Royaume {
public:
    void effet(Joueur j) override;
};

#endif