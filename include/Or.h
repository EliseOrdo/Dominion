#ifndef OR_H
#define OR_H
#include "Tresor.h"
class Or: public Tresor {
public:
    Or();
    Carte* dupliquer() const override{return new Or();}
};

#endif