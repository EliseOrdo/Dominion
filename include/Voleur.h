#ifndef VOLEUR_H
#define VOLEUR_H
#include "Attaque.h"

class Voleur : virtual Attaque {
public:
    void effet(Joueur j) override;
};

#endif