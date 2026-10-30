#ifndef SALLETRONE_H
#define SALLETRONE_H
#include "Action.h"

class SalleDuTrone : public Action {
public:
    SalleDuTrone();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new SalleDuTrone();}
};

#endif