#ifndef VOLEUR_H
#define VOLEUR_H
#include "Attaque.h"

class Voleur : public Attaque {
public:
    void effet(Joueur j) override;
};

#endif