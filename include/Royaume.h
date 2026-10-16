#ifndef ROYAUME_H
#define ROYAUME_H
#include "Carte.h"
#include "Joueur.h"
class Royaume : public virtual Carte{
public :
    virtual void effet(Joueur j);
};

#endif