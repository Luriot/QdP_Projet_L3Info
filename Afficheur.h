#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "AireDeJeu.h"




class afficheur{
public:
    virtual ~afficheur() = default;
    virtual void afficheAdj(const AireDeJeu &Adj) const = 0;
};


class afficheConsole: public afficheur{

public:
    virtual void afficheAdj(const AireDeJeu &Adj) const override;
};












#endif // AFFICHEUR_H
