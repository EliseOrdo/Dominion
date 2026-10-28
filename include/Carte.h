#ifndef CARTE_H
#define CARTE_H
#include <string>

class Carte {
protected:
    std::string nom;
    int cout;
    std::string description;
public:
    friend std::ostream& operator <<(std::ostream& os,Carte& carte);
    friend std::ostream& operator <<(std::ostream& os,Carte* carte);
    std::string getNom();
    virtual Carte* dupliquer() const = 0;
    virtual ~Carte() = default;
};

#endif