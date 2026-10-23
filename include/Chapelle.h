#ifndef CHAP_H
#define CHAP_H
#include "Royaume.h"

class Chapelle : virtual Royaume {
public:
    void effet(Joueur j) override;
};

#endif