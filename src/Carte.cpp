#include "Carte.h"
#include <iostream>

std::ostream& operator <<(std::ostream& os,Carte& carte){
    return os<<"nom : "<<carte.nom<<"\ndescription : "<<carte.description<<"\ncout : "<<carte.cout<<"\n";
}

std::ostream& operator <<(std::ostream& os,Carte* carte){
    return os<<"nom : "<<carte->nom<<"\ndescription : "<<carte->description<<"\ncout : "<<carte->cout<<"\n";
}

std::string Carte::getNom(){
    return nom;
}

int Carte::getCout(){
    return cout;
}