#ifndef CHAP_H
#define CHAP_H
#include "Action.h"


class Chapelle : public Action {
public:
    Chapelle();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Chapelle();}
};

#endif