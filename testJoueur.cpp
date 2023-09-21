#include "doctest.h"
#include "joueur.h"

TEST_CASE("Création d'un joueur Normal")
{
    point pos{3,4};
    joueurNormal j{pos};
    SUBCASE("test si le joueur est en vie")
    {
        bool vie = j.estVivant();
        REQUIRE_UNARY(vie);
    }
    SUBCASE("test si la position donnée en parametre est celle du joueur")
    {
        point position = j.position();
        REQUIRE_EQ(pos, position);
    }
}

TEST_CASE("Création d'un joueur Expert")
{
    point pos{3,4};
    joueurExpert j{pos};
    SUBCASE("test si le joueur est en vie")
    {
        bool vie = j.estVivant();
        REQUIRE_UNARY(vie);
    }
    SUBCASE("test si la position donnée en parametre est celle du joueur")
    {
        point position = j.position();
        REQUIRE_EQ(pos, position);
    }
}
TEST_CASE("Test le temps de survie du joueur")
{
    point pos{2,1};
    joueurNormal j(pos);
    int lifetime = j.lifetime();
    REQUIRE_EQ(lifetime,j.lifetime());
}

TEST_CASE("Test l'état du joueur")
{
    point pos{2,1};
    joueurNormal j(pos);
    bool alive = true;
    REQUIRE_EQ(alive,j.estVivant());
}

TEST_CASE("Test si le joueur meurt")
{
    point pos{2,1};
    joueurNormal j(pos);
    bool dead = false;
    j.setDeath();
    REQUIRE_EQ(dead,j.estVivant());
}

TEST_CASE("Test si la position du joueur")
{
    point pos{2,1};
    joueurNormal j(pos);
    point pos1 = j.position();
    REQUIRE_EQ(pos1,j.position());
}

//FAIRE DEPLACEMENT JOUEURNORMAL ET JOUEUREXPERT