#include <iostream>
#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
#include "Archer.h"
#include "Catapulte.h"
#include "ConsoleColor.h"
void actionsT(bool b, Battlefield battlefield);
void actionsF(bool b, Battlefield battlefield);

void buy(bool b, Fort *pFort, Battlefield battlefield);

int main() {
    std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl
              << "----------------------------------------Age of War : Version Eco +---------------------------------"<<std::endl
              << "---------------------------------------------------------------------------------------------------"<<std::endl;


    Battlefield b;
    Fort *f1= new Fort(&b, true);//A
    Fort *f2= new Fort(&b, false);//B
    b.Generer(f1,f2);
    auto*f=new Archer(0,100,47,25,24,25,&b,true);
    auto*f7=new Fantassin(7,100,47,25,24,25,&b,false);
    auto*f3=new Archer(3,100,47,25,24,25,&b,true);
    auto*f4=new Catapulte(4,100,47,25,24,25,&b,false);
    auto*f5=new Fantassin(5,100,47,25,24,25,&b,true);
    auto*f8=new Fantassin(8,100,47,25,24,25,&b,false);
    auto*f9=new Fantassin(9,100,47,25,24,25,&b,true);
    auto*f10=new Fantassin(10,100,47,25,24,25,&b,false);

    b.Generer(f1,f2);
    //b.addUnit(f7,0);
    //b.addUnit(f3,1);
    b.addUnit(f5,2);
    //b.addUnit(f8,3);
    //b.addUnit(f4,4);
    //b.addUnit(f9,5);
    //b.addUnit(f10,6);
    //b.addUnit(f10,9);
    //b.addUnit(f4,10);
    //b.addUnit(f5,11);
    int compteur = 0;
    while(true)
    {
        std::cout<< "Round numero " << compteur << std::endl;
        std::cout<< "Les deux equipes recoit 8 gold."  << std::endl;
        f1->setGold(8);
        f2->setGold(8);
        compteur++;
        //actionsT(true,b);
        //buy(true,f1,b);
        //actionsF(false,b);
        //buy(true,f2,b);
        std::cout<<red<<f1->print()<<white<<"                                      "<<blue<<f2->print() <<white<<std::endl;
        std::cout <<b;
        b.getCase(2).getE()->action2();


        if(f1->getHp() <= 0){
            std::cout<< "Round limite atteinte";
            b.~Battlefield();
            break;
        }
        if(f2->getHp() <= 0){
            std::cout<< "Equipe Rouge Gagne";
            b.~Battlefield();
            break;
        }
        if(compteur>15){
            std::cout<< "Tour max atteint";
            b.~Battlefield();
            break;
        }
        std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl;
    }
    return 0;
}


void actionsT(bool b, Battlefield bf) {
    for (int i = 0; i < 12; i++) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action1();
        }
    }
    for (int i = 11; i >=0; i--) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action2();
        }
    }
    for (int i = 11; i >=0; i--) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action3();
        }
    }
}
void actionsF(bool b, Battlefield bf) {
    for (int i = 11; i >=0; i--) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action1();
        }
    }
    for (int i = 11; i >=0; i--) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action2();
        }
    }
    for (int i = 0; i < 12; i++) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action3();
        }
    }
}
void buy(bool b, Fort *pFort, Battlefield battlefield) {
    std::cout<< "Vous avez " << pFort->getGold() <<"golds. Voulez vous acheter?" << std::endl;
    if (b)
        std::cout <<"Tapez F pour Fantassin,A pour Archer et C pour Catapulte";
    else
        std::cout <<"Tapez F pour Fantassin,A pour Archer et C pour Catapulte";
}
