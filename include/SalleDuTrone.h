#ifndef SALLETRONE_H
#define SALLETRONE_H
#include "Royaume.h"

class SalleDuTrone : public Royaume {
public:
    SalleDuTrone();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new SalleDuTrone();}
};

#endif