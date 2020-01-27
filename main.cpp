#include <iostream>


#include "Fantassin.h"
#include "Battlefield.h"
#include "Archer.h"
#include "Catapulte.h"
#include "ConsoleColor.h"
void actionsT(bool b, Battlefield& bf);
void actionsF(bool b, Battlefield& bf);

void buy(bool b, Fort *pFort, Battlefield& battlefield);


int main() {
    std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl
              << "----------------------------------------Age of War : Version Eco +---------------------------------"<<std::endl
              << "---------------------------------------------------------------------------------------------------"<<std::endl;


    Battlefield b;//création plateau
    Fort *f1= new Fort(&b, true);//EQUIPE BLEU
    Fort *f2= new Fort(&b, false);//EQUIPE RED
    b.Generer(f1,f2);//générer les forts dans plateau
    bool run=true;//Stopper le programme
    int compteur = 0;
    while(run) //boucle pour chaque tour
    {
        std::cout<< white<< "Round numero " << compteur << std::endl;
        std::cout<< "Les deux equipes recoit 8 golds."  << std::endl;
        f1->setGold(f1->getGold()+8);//gagne 8 gold
        f2->setGold(f2->getGold()+8);
        compteur++;

        std::cout<<blue<<f1->print()<<white<<"                                      "<<red<<f2->print() <<white<<std::endl; //afichage donnée fort
        std::cout <<b;//affichage du plateau
        actionsT(true,b);//ensemble actions coté bleu
        buy(true,f1,b);//shopping time bleu
        actionsF(false,b);//ensemble actions coté rouge
        buy(false,f2,b);// shopping time rouge

        std::cout<<blue<<f1->print()<<white<<"                                      "<<red<<f2->print() <<white<<std::endl;
        std::cout <<b;//réafficha données plateau

        //vérification conditions d'arret

        if(f1->getHp() <= 0){//vérification mort fort1
            std::cout<<green<< "Equipe Rouge Gagne"<<white <<std::endl;
            b.~Battlefield();
            run=false;
            std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl;
            break;
        }
        if(f2->getHp() <= 0){//vérification mort fort2
            std::cout<<green<< "Equipe Bleu Gagne"<<white<< std::endl;
            b.~Battlefield();
            run=false;
            std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl;
            break;
        }
        if(compteur>3){//limite de nombre de tour
            std::cout<<green<< "Tour max atteint"<<white<< std::endl;
            b.~Battlefield();
            run=false;
            std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl;
            break;
        }
        std::cout << "---------------------------------------------------------------------------------------------------"<<std::endl;
    }
    std::cout << "Hehe" ;
    return 0;
}


void actionsT(bool b, Battlefield& bf) {//actions coté bleu
    for (int i = 0; i < 12; i++) {//parcours des unit de gauche à droite pour action1
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action1();
        }
    }
    for (int i = 11; i >=0; i--) {//parcours des unit de droite à gauche pour action2
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action2();
            }
        }
    for (int i = 11; i >=0; i--) {//parcours des unit de droite à gauche pour action3
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action3();
        }
    }
}
void actionsF(bool b, Battlefield& bf) {
    for (int i = 11; i >=0; i--) {//parcours des unit de droite à gauche pour action1
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action1();
        }
    }
    for (int i = 0; i < 12; i++) {//parcours des unit de gauche à droite pour action2
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action2();
        }
    }
    for (int i = 0; i < 12; i++) {//parcours des unit de gauche à droite pour action3
        if (!bf.getCase(i).checkFree()){
            if(bf.getCase(i).getE()->isTeam() == b)
                bf.getCase(i).getE()->action3();
        }
    }
}
void buy(bool b, Fort *pFort, Battlefield& battlefield) {//achat unité
    int Choix,FortPos;
        if (b){
        FortPos=0;
        std::cout << blue << "Equipe Bleu"<<std::endl;
    } else{
        FortPos=11;
        std::cout << red << "Equipe Rouge"<<std::endl;
    }
    std::cout<< "Vous avez " << pFort->getGold() <<" golds." << std::endl << "Tapez 1 pour Fantassin,2 pour Archer et 3 pour Catapulte et 0 pour ne pas acheter"<<white<<std::endl;//affichage montant possédé
    std::cin>>Choix;
    switch (Choix){
        case 1://achat fantassin
            if(battlefield.checkCase(FortPos) && pFort->getGold() >= 10){//vérification du compte bancaire
                battlefield.addUnit(new Fantassin(FortPos,10,10,94,1,1,&battlefield,b),FortPos);//génération sur terrain
                std::cout <<"Ajout d'un Fantassin"<< std::endl;
                pFort->setGold(pFort->getGold()-10);//retrait bancaire
                break;
            }else{
                std::cout<<"Impossible : Erreur Position ou Argent" << std::endl;
                break;
            }
        case 2://achat archer
            if(battlefield.checkCase(FortPos) && pFort->getGold() >= 12){//vérification du compte bancaire
                battlefield.addUnit(new Archer(FortPos,7,12,93,1,3,&battlefield,b),FortPos);//génération sur terrain
                std::cout <<"Ajout d'un Archer"<< std::endl;
                pFort->setGold(pFort->getGold()-12);//retrait bancaire
                break;
            }else{
                std::cout<<"Impossible : Erreur Position ou Argent" << std::endl;
                break;
            }
        case 3://achat catapulte
            if(battlefield.checkCase(FortPos) && pFort->getGold() >= 22){//vérification du compte bancaire
                battlefield.addUnit(new Catapulte(FortPos,12,22,96,2,4,&battlefield,b),FortPos);//génération sur terrain
                std::cout << "Ajout d'un Catapulte" << std::endl;
                pFort->setGold(pFort->getGold()-22);//retrait bancaire
                break;

            }else{
                std::cout<<"Impossible : Erreur Position ou Argent" << std::endl;
                break;
            }
        case 0:
            std::cout<<"On ne fait rien"<<std::endl;
            break;

        default:
            break;

    }
}

