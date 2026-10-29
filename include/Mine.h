#ifndef MINE_H
#define MINE_H
#include "Action.h"
class Mine: public Action {
public:
    Mine();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Mine();}
};

#endif