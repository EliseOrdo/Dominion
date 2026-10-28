#ifndef CHAP_H
#define CHAP_H
#include "Royaume.h"


class Chapelle : public Royaume {
public:
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new Chapelle();}
};

#endif