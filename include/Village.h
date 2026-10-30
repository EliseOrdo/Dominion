#ifndef VILLAGE_H
#define VILLAGE_H
#include "Royaume.h"

class Village : public Royaume {
public:
    Village();
    Carte* dupliquer() const override{return new Village();}
    void effet(Joueur* j) override;
};

#endif