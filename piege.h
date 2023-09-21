#ifndef PIEGE_H
#define PIEGE_H

#include "entity.h"

class piege : public StaticEntity
{
public:
    virtual ~piege() = default;
};

class piegeAPic : public piege
{
public:
    piegeAPic(const point& pos, int taille);
    point position() const override;
    bool estActif() const override;
    int taille() const;
    void increaseTaille(AireDeJeu& AdJ);
private:
    point d_pos;
    bool d_actif;
    int d_taille;
};

#endif // PIEGE_H
