#ifndef CDC_H
#define CDC_H
#include "Action.h"

class ChambreDuConseil: public Action {
public:
    ChambreDuConseil();
    void effet(Joueur* j) override;
    Carte* dupliquer() const override{return new ChambreDuConseil();}
};

#endif