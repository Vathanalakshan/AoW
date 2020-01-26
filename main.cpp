#include <iostream>

#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
#include "Archer.h"
#include "Catapulte.h"
#include "ConsoleColor.h"
void actionsT(bool b, Battlefield& bf);
void actionsF(bool b, Battlefield& bf);

void buy(bool b, Fort *pFort, Battlefield& battlefield);

std::ostream &coul(std::ostream &s);

int main() {
    std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl
              << "----------------------------------------Age of War : Version Eco +---------------------------------"<<std::endl
              << "---------------------------------------------------------------------------------------------------"<<std::endl;


    Battlefield b;
    Fort *f1= new Fort(&b, true);//EQUIPE BLEU
    Fort *f2= new Fort(&b, false);//EQUIPE RED
    b.Generer(f1,f2);
    auto*f=new Archer(1,100,47,25,1,3,&b,true);
    auto*f7=new Fantassin(7,100,47,25,1,1,&b,false);
    auto*f3=new Archer(4,100,47,25,1,3,&b,true);
    auto*f4=new Catapulte(6,100,47,25,2,3,&b,false);
    auto*f5=new Fantassin(5,100,47,25,1,1,&b,true);
    auto*f8=new Fantassin(8,100,47,25,1,1,&b,false);
    auto*f9=new Fantassin(9,100,47,25,1,1,&b,true);
    auto*f10=new Fantassin(10,100,47,25,1,1,&b,false);

    b.Generer(f1,f2);
    //b.addUnit(f7,f7->getPos());
    //b.addUnit(f3,f3->getPos());
    //b.addUnit(f5,f5->getPos());
    //b.addUnit(f8,f8->getPos());
    //b.addUnit(f4,f4->getPos());
    //b.addUnit(f9,f9->getPos());
    //b.addUnit(f10,f10->getPos());
    //b.addUnit(f10,f10->getPos());
    //b.addUnit(f4,1);
    //b.addUnit(f5,11);
    int compteur = 0;
    while(true)
    {
        std::cout<< white<< "Round numero " << compteur << std::endl;
        std::cout<< "Les deux equipes recoit 8 golds."  << std::endl;
        f1->setGold(f1->getGold()+8);
        f2->setGold(f2->getGold()+8);
        compteur++;

        std::cout<<blue<<f1->print()<<white<<"                                      "<<red<<f2->print() <<white<<std::endl;
        std::cout <<b;

        actionsT(true,b);
        buy(true,f1,b);
        actionsF(false,b);
        buy(false,f2,b);

        std::cout<<blue<<f1->print()<<white<<"                                      "<<red<<f2->print() <<white<<std::endl;
        std::cout <<b;

        if(f1->getHp() <= 0){
            std::cout<< "Equipe Rouge Gagne";
            b.~Battlefield();
            break;
        }
        if(f2->getHp() <= 0){
            std::cout<<green<< "Equipe Bleu Gagne"<< std::endl;
            b.~Battlefield();
            break;
        }
        if(compteur>1500){
            std::cout<<green<< "Tour max atteint"<< std::endl;
            b.~Battlefield();
            break;
        }
        std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl;
    }
    return 0;
}


void actionsT(bool b, Battlefield& bf) {
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
void actionsF(bool b, Battlefield& bf) {
    for (int i = 11; i >=0; i--) {
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action1();
        }
    }
    for (int i = 0; i < 12; i++) {
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
void buy(bool b, Fort *pFort, Battlefield& battlefield) {
    int Choix,FortPos;
        if (b){
        FortPos=0;
        std::cout << blue << "Equipe Bleu"<<std::endl;
    } else{
        FortPos=11;
        std::cout << red << "Equipe Rouge"<<std::endl;
    }
    std::cout<< "Vous avez " << pFort->getGold() <<" golds." << std::endl << "Tapez 1 pour Fantassin,2 pour Archer et 3 pour Catapulte et 0 pour ne pas acheter"<< std::endl;
    std::cin>>Choix;
    switch (Choix){
        case 1:
            if(battlefield.checkCase(FortPos) && pFort->getGold() >= 10){
                battlefield.addUnit(new Fantassin(FortPos,10,10,94,1,1,&battlefield,b),FortPos);
                std::cout <<"Ajout d'un Fantassin"<< std::endl;
                pFort->setGold(pFort->getGold()-10);
            }else{
                std::cout<<"Impossible : Erreur Position ou Argent" << std::endl;
                break;
            }
        case 2:
            if(battlefield.checkCase(FortPos) && pFort->getGold() >= 12){
                battlefield.addUnit(new Archer(FortPos,7,12,93,1,3,&battlefield,b),FortPos);
                std::cout <<"Ajout d'un Archer"<< std::endl;
                pFort->setGold(pFort->getGold()-12);
            }else{
                std::cout<<"Impossible : Erreur Position ou Argent" << std::endl;
                break;
            }
        case 3:
            if(battlefield.checkCase(FortPos) && pFort->getGold() >= 22){
                battlefield.addUnit(new Catapulte(FortPos,12,22,96,2,4,&battlefield,b),FortPos);
                std::cout << "Ajout d'un Catapulte" << std::endl;
                pFort->setGold(pFort->getGold()-22);
            }else{
                std::cout<<"Impossible : Erreur Position ou Argent" << std::endl;
                break;
            }
        case 0:
            std::cout<<"On ne fait rien"<<std::endl;
            break;
    }
}

