#include "doctest.h"
#include "piege.h"
#include "AireDeJeu.h"


TEST_CASE("Le piege � pic fonctionne")
{
    AireDeJeu a{6,6};
    point pos{5,4};
    int t = 3;
    piegeAPic p{pos,t};
    SUBCASE("test si le piege � pic cree est actif")
    {
        bool actif = p.estActif();
        REQUIRE_UNARY(actif);     //test si d_actif = true
    }
    SUBCASE("test si le piege � pic est cree a la position donnee en parametre")
    {
        point position = p.position();
        REQUIRE_EQ(pos, position);    //test si la position est correcte
    }
    SUBCASE("test si le piege � pic est cree avec la taille donnee en parametre")
    {
        int taille = p.taille();
        REQUIRE_EQ(taille, t);    //test si la taille est correcte
    }
    SUBCASE("test si piege � pic se desactive quand il est plein")
    {
        for( int i = p.taille()-1 ; i >= 0 ; --i )
        {
            p.increaseTaille(a);
        }
        bool actif = p.estActif();
        int taille = p.taille();
        REQUIRE_EQ(taille, 0);        //test  si la taille de d_empile = 0
        REQUIRE_UNARY_FALSE(actif);    //test si le piege = false
    }
}
