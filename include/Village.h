#ifndef VILLAGE_H
#define VILLAGE_H
#include "Action.h"

class Village : public Action {
public:
    Village();
    Carte* dupliquer() const override{return new Village();}
    void effet(Joueur* j) override;
};

#endif