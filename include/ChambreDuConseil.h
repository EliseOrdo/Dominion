#ifndef CDC_H
#define CDC_H
#include "Royaume.h"

class ChambreDuConseil: public Royaume {
public:
    ChambreDuConseil();
    void effet(Joueur j) override;
    Carte* dupliquer() const override{return new ChambreDuConseil();}
};

#endif