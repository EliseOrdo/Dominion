#ifndef ACTION_H
#define ACTION_H
#include "Royaume.h"
#include "Joueur.h"

class Action : public virtual Royaume{
public :
    virtual void effet(Joueur* j) = 0;
};

#endif