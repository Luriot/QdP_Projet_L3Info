#ifndef JOUEUR_H
#define JOUEUR_H


#include "entity.h"

#include "AireDeJeu.h"


class joueur : public DynamicEntity{
public:
    joueur(const point& pos);

    int lifetime() const;
    void setDeath();
    bool estVivant() const override;
    point position() const override;
    virtual void deplacement( AireDeJeu& AdJ, int valeur) = 0;
protected:
    point d_pos;
    bool d_alive;
    int d_lifetime;
};

// Avance avec diagonales
class joueurNormal : public joueur{
public:
    joueurNormal(const point& pos);
    void deplacement( AireDeJeu& AdJ, int valeur) override;
};

// Avance sans diagonales
class joueurExpert : public joueur{
public:
    joueurExpert(const point& pos);
    void deplacement( AireDeJeu& AdJ, int valeur) override;
};



#endif // JOUEUR_H



