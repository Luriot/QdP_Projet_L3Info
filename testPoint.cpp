#include "doctest.h"
#include "point.h"

TEST_CASE("Création du point")
{
    int a = 0; int b = 1;
    point p{a,b};
    SUBCASE("test si x donné en paramètre est bien x()")
    {
        REQUIRE_EQ(a,p.x());
    }
    SUBCASE("test si y donné en paramètre est bien y()")
    {
        REQUIRE_EQ(b,p.y());
    }
}

TEST_CASE("Verifie si setx applique un x en parametre")
{
    point p{0,0};
    int a=5;
    p.setx(a);
    REQUIRE_EQ(a,p.x());
}

TEST_CASE("Verifie si setx applique un x en parametre")
{
    point p{0,0};
    int a=5;
    p.sety(a);
    REQUIRE_EQ(a,p.y());
}

TEST_CASE("Verifie la surcharge d'operateur ==")
{
    point p1{0,0};
    point p2{0,0};
    bool egalite = (p1.x()== p2.x() && p1.y() == p2.y());
    REQUIRE_EQ(egalite,p1==p2);
}
