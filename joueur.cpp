#include "joueur.h"




joueur::joueur(const point& pos) : d_pos{pos}, d_alive{true}, d_lifetime{0}
{}

int joueur::lifetime() const
{
    return d_lifetime;
}


void joueur::setDeath()
{
    d_alive = false;
}


bool joueur::estVivant() const
{
    return d_alive;
}


point joueur::position() const
{
    return d_pos;
}



joueurNormal::joueurNormal(const point& pos) : joueur{pos}
{}


void joueurNormal::deplacement( AireDeJeu& AdJ,int valeur)
{
    point d_temp = d_pos;
    switch(valeur)
    {
        case 1:
            d_temp.sety(d_temp.y()-1);
            d_temp.setx(d_temp.x()+1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;

        case 2:
            d_temp.setx(d_temp.x()+1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 3:
            d_temp.sety(d_temp.y()+1);
            d_temp.setx(d_temp.x()+1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 4:
            d_temp.sety(d_temp.y()-1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 6:
            d_temp.sety(d_temp.y()+1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 7:
            d_temp.sety(d_temp.y()-1);
            d_temp.setx(d_temp.x()-1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 8:
            d_temp.setx(d_temp.x()-1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 9:
            d_temp.sety(d_temp.y()+1);
            d_temp.setx(d_temp.x()-1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
    }
    d_lifetime += 1;
}

joueurExpert::joueurExpert(const point& pos) : joueur{pos}
{}

void joueurExpert::deplacement( AireDeJeu& AdJ,int valeur)
{
    point d_temp = d_pos;
    switch(valeur)
    {
        case 2:
            d_temp.setx(d_temp.x()+1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 4:
            d_temp.sety(d_temp.y()-1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 6:
            d_temp.sety(d_temp.y()+1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
        case 8:
            d_temp.setx(d_temp.x()-1);
            if(AdJ.estDansTableau(d_temp) && AdJ.estLibre(d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
            break;
    }
    d_lifetime += 2;
}
