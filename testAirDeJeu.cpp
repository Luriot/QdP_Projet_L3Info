#include"doctest.h"
#include"AireDeJeu.h"

point p{5,6};
AireDeJeu aire{10,15};

TEST_CASE("Tester si un point est dans le tableau ")
{
    REQUIRE_UNARY(aire.estDansTableau(p));
}

TEST_CASE("Tester si une case est libre")
{
    REQUIRE_UNARY(aire.estLibre(p));
}

TEST_CASE("Renvoie si un type d'entite occupe une position donnee")
{
    aire.setValue(p,3);
    REQUIRE_UNARY(aire.estOccupeType(3,p));
}

TEST_CASE("Tester la position du joueur")
{
    point x = aire.posJoueur();
    REQUIRE_EQ(x,aire.posJoueur());
}

TEST_CASE("Tester la tailleL")
{
    REQUIRE_EQ(aire.tailleL(),15);
}

TEST_CASE("Tester la tailleC")
{
    REQUIRE_EQ(aire.tailleC(),10);
}


