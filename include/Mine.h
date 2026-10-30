#ifndef MINE_H
#define MINE_H
#include "Royaume.h"
class Mine: public Royaume {
public:
    Mine();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new Mine();}
};

#endif