#include <iostream>
#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
#include "Archer.h"
#include "Catapulte.h"

int main() {
    std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl
              << "----------------------------------------Age of War : Version Eco +---------------------------------"<<std::endl
              << "---------------------------------------------------------------------------------------------------"<<std::endl;


    Battlefield b;
    Fort *f1=new Fort(0,&b,true);//A
    Fort *f2=new Fort(11,&b,false);//B
    b.Generer(f1,f2);
    int compteur = 0;
    while(true)
    {
        std::cout<< "Round numero " << compteur << std::endl;
        std::cout<< "Les deux equipes recoit 8 gold."  << std::endl;
        f1->setGold(8);
        f2->setGold(8);
        compteur++;
        std::cout <<b;
        if(compteur>15){
            break;
        }

    }
    return 0;
}
