#ifndef VILLAGE_H
#define VILLAGE_H
#include "Royaume.h"

class Village : virtual Royaume {
public:
    Village();

    void effet(Joueur j) override;
};

#endif