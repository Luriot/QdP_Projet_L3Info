#include "doctest.h"
#include "fauve.h"
#include "piege.h"
#include "AireDeJeu.h"

TEST_CASE("test sur la creation d'un lion")
{
    point pos{5,4};
    lion l{pos};
    SUBCASE("test si le lion est en vie")
    {
        bool vie = l.estVivant();
        REQUIRE_UNARY(vie);     //test si d_alive = true
    }
    SUBCASE("test si le lion est cree a la position donnee en parametre")
    {
        point position = l.position();
        REQUIRE_EQ(pos, position);    //test si la position est correcte
    }
}

TEST_CASE("test sur la creation d'un tigre")
{
    point pos{5,4};
    tigre t{pos};
    SUBCASE("test si le tigre est en vie")
    {
        bool vie = t.estVivant();
        REQUIRE_UNARY(vie);     //test si d_alive = true
    }
    SUBCASE("test si le tigre est cree a la position donnee en parametre")
    {
        point position = t.position();
        REQUIRE_EQ(pos, position);    //test si la position est correcte
    }
}


TEST_CASE("test tableau de fauve")
{
    std::vector<std::unique_ptr<fauve>>fauves;
    point pos1{5,4};
    fauves.push_back(std::make_unique<lion>(pos1));


    point pos2{4,4};
    fauves.push_back(std::make_unique<lion>(pos2));

    point pos3{4,3};
    fauves.push_back(std::make_unique<lion>(pos3));


    std::vector<std::unique_ptr<piegeAPic>> pieges;
    point posp{5,4};
    int t = 3;
    pieges.push_back(std::make_unique<piegeAPic>(posp,t));

    SUBCASE("test si on tue un fauve")
    {
        int nbVivant=0;
        for(int i=0;i<fauves.size();++i)
            if(fauves[i]->estVivant())
                nbVivant++;

        killFauve(pos3,fauves);

        int nbVivant1=0;
        for(int i=0;i<fauves.size();++i)
            if(fauves[i]->estVivant())
                nbVivant1++;

        REQUIRE_GT(nbVivant,nbVivant1);  //test si taille2 < taille1 et donc qu'on a tuer un fauve
    }
    SUBCASE("test si le piege tue un fauve et que sa taille diminue")
    {
        AireDeJeu a{6,6};
        int nbVivant = 0;
        for(int i=0;i<fauves.size();++i)
            if(fauves[i]->estVivant())
                nbVivant++;
        int nb1 = pieges[0]->taille();
        killPiegeAPic(pos1,a,pieges,fauves);
        int nbVivant1=0;
        for(int i=0;i<fauves.size();++i)
            if(fauves[i]->estVivant())
                nbVivant1++;
        int nb2 = pieges[0]->taille();
        REQUIRE_LT(nbVivant1,nbVivant);  //test si taille2 < taille1 et donc qu'on a tuer un fauve
        REQUIRE_LT(nb2,nb1);      //test si la taille du piege diminue
    }
}


TEST_CASE("test le deplacement d'un tigre")
{
    std::vector<std::unique_ptr<fauve>>fauves;
    point pos1{2,2};


    std::vector<std::unique_ptr<joueur>> joueurs;

    std::vector<std::unique_ptr<piegeAPic>> pieges;
    point posp{4,4};
    int t = 3;
    pieges.push_back(std::make_unique<piegeAPic>(posp,t));

    AireDeJeu A{5,5};


    SUBCASE("test si le tigre se deplace en haut à droite")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,1}));
        fauves.push_back(std::make_unique<tigre>(point{1,0}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()-1);
        pos1.sety(pos1.y()+1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace en haut à gauche")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,0}));
        fauves.push_back(std::make_unique<tigre>(point{1,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()-1);
        pos1.sety(pos1.y()-1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace en haut")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,1}));
        fauves.push_back(std::make_unique<tigre>(point{1,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()-1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace en bas à droite")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{1,1}));
        fauves.push_back(std::make_unique<tigre>(point{0,0}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()+1);
        pos1.sety(pos1.y()+1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace en bas à gauche")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{1,0}));
        fauves.push_back(std::make_unique<tigre>(point{0,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()+1);
        pos1.sety(pos1.y()-1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace en bas ")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{1,1}));
        fauves.push_back(std::make_unique<tigre>(point{0,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()+1);;
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace  à gauche")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,0}));
        fauves.push_back(std::make_unique<tigre>(point{0,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.sety(pos1.y()-1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le tigre se deplace à droite")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,1}));
        fauves.push_back(std::make_unique<tigre>(point{0,0}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.sety(pos1.y()+1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
}

TEST_CASE("test le deplacement d'un lion")
{
    std::vector<std::unique_ptr<fauve>>fauves;
    point pos1{2,2};


    std::vector<std::unique_ptr<joueur>> joueurs;

    std::vector<std::unique_ptr<piegeAPic>> pieges;
    point posp{4,4};
    int t = 3;
    pieges.push_back(std::make_unique<piegeAPic>(posp,t));

    AireDeJeu A{5,5};

    SUBCASE("test si le lion se deplace en haut")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,1}));
        fauves.push_back(std::make_unique<lion>(point{1,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()-1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le lion se deplace en bas ")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{1,1}));
        fauves.push_back(std::make_unique<lion>(point{0,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.setx(pos1.x()+1);;
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le lion se deplace  à gauche")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,0}));
        fauves.push_back(std::make_unique<lion>(point{0,1}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.sety(pos1.y()-1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
    SUBCASE("test si le lion se deplace à droite")
    {
        joueurs.push_back(std::make_unique<joueurNormal>(point{0,1}));
        fauves.push_back(std::make_unique<lion>(point{0,0}));
        point pos1= fauves[0]->position();
        fauves[0]->deplacement(A,joueurs,fauves,pieges);
        pos1.sety(pos1.y()+1);
        REQUIRE_EQ(pos1,fauves[0]->position());
    }
}

