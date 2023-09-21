#include "Afficheur.h"
#include "point.h"

#include "iomanip"
#include "iostream"


void afficheConsole::afficheAdj(const AireDeJeu &Adj) const
{



    for(int i=0; i<Adj.tailleL();i++)
    {


        for(int k=0; k<Adj.tailleC()*7;k++)
            std::cout<<std::left<<std::setw(1)<<'-';

        std::cout<<std::endl;




        for(int j=0;j<Adj.tailleC();j++)
        {
            point p{i,j};
            std::cout<<std::left<<std::setw(3)<<'|'<<std::left<<std::setw(3);
            if(Adj.estOccupeType(0,p))
                std::cout<<' '<<'|';

            else if(Adj.estOccupeType(1,p))
                std::cout<<'J'<<'|';

            else if(Adj.estOccupeType(2,p))
                std::cout<<'L'<<'|';

            else if(Adj.estOccupeType(3,p))
                std::cout<<'T'<<'|';

            else if(Adj.estOccupeType(4,p))
                std::cout<<'P'<<'|';




        }
        std::cout<<'|'<<std::endl;
    }
    for(int k=0; k<Adj.tailleC()*7;k++)
            std::cout<<std::left<<std::setw(1)<<'-';

        std::cout<<std::endl;
}
